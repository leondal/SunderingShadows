// Earthenair

#include <std.h>
#include <daemons.h>

inherit SPELL;

object sword;

create() {
    ::create();
    set_spell_name("earthenair");
    set_spell_level(3);
    set_spell_type("priest");
    set_spell_sphere("elemental earth");
    set_diety("grumbar");
    set_target_required(1);
    set_verbal_comp();
    set_somatic_comp();
}

string query_cast_string() {
    return "%^ORANGE%^"+caster->query_cap_name()+" looks at the ground around "+target->query_cap_name()+" and spreads "+caster->query_possessive()+" arms wide and calls for Grumbar's aid!";
}

int preSpell() {
    if (!objectp(caster)) return 0;
    if (caster->query_property("earthenair")) {
        tell_object(caster,"You are already concentrating on a earthenair spell.");
        return 0;
    }
    return 1;
}
spell_effect(int prof) {
    int num,i,skinned,dam;

    if (!objectp(TO)) return;
    if (!objectp(target)) {
        dest_effect();
        return;
    }
    if (!objectp(caster)) {
        dest_effect();
        return ;
    }
    if (environment(caster) != place) {
        dest_effect();
        return;
    }

    if (target->query_ghost()) {
        dest_effect();
        return;
    }

    num = clevel+1+random(4);
    tell_object(target,"%^ORANGE%^The ground around you surges up violently and you are pelted with dirt and rocks.");
    tell_room(environment(target),"%^ORANGE%^The ground around "+target->query_cap_name()+" surges up violently and "+target->query_subjective()+" is pelted with dirt and rocks.%^RESET%^",target);
    if (skinned = (int)(target->query_stoneSkinned())) {
        if (skinned > num)
            target->set_stoneSkinned(skinned - num);
        else
            target->set_stoneSkinned(0);
    }

    if ((dam = num*(random(4)+1))>100) dam = 100;
    if (!(SAVING_D->saving_throw(target,"spell",-4)))
        damage_targ(target,"torso",dam);
    else damage_targ(target,"torso",dam/2);
    spell_successful();
    caster->set_property("earthenair",1);
    caster->set_property("spelled", ({TO}) );
    call_out("spell_effect",6);
    if (clevel*2 > 31) call_out("dest_effect",31);
    else call_out("dest_effect",clevel*2);
}

void dest_effect() {
    if(objectp(caster)){
        caster->remove_property("earthenair");
        caster->remove_property_value("spelled", ({TO}) );
        ::dest_effect();
        remove_call_out("spell_effect");
    }
    TO->remove();
}

int help(string str) {
    write(
@HELP
Spell  : Earthenair
Level  : 3rd Level
Sphere : Elemental Earth
Deity  : Grumbar
Syntax : chant earthenair on <target>

This spell will cause the ground around the target
to erupt and throw dirt and rocks at the target.
HELP
);
    return 1;
}
