#include <spell.h>
#include <magic.h>
#include <rooms.h>

inherit SPELL;

int damage;
int clevel, num;
string target_limb;
object caster, target;

create() {
    ::create();
    set_spell_name("bolt of glory");
    set_spell_level(6);
    set_spell_type("priest");
    set_spell_sphere("combat");
    set_diety("torm");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
}

spell_effect(int prof) {
    caster = CASTER;
    target = TARGET;
    place = PLACE;
    clevel = CLEVEL;
    damage = 0;
    spell_successful();

    if (environment(caster) != environment(target)){
        tell_object(caster, "Your target has left your range.");
        TO->remove();
        return;
    }
    for (num=0;num < clevel;num++) {
        damage += random(6) + 1;
    }

    target_limb = target->return_target_limb();
    if (interactive(caster)) {
        tell_object(caster, "%^BOLD%^You call to your god Torm, and gather the pure glory that is he, and hurl it at "+target->query_cap_name()+"!!");
        tell_object(target, "%^BOLD%^"+caster->query_cap_name()+" calls upon the glory that is Torm, creating a bolt of that glory, hurling its biting edge at you!");
        tell_room(place, "%^BOLD%^"+caster->query_cap_name()+" gathers the glory that is Torm from around him, forming it into a great bolt of Glory, then hurls it at "+target->query_cap_name()+"!", ({caster, target}) );
    } else {
        tell_object(target, "%^BOLD%^"+caster->query_cap_name()+" calls upon the glory that is Torm, creating a bolt of that glory, hurling its biting edge at you!");
        tell_room(place, "%^BOLD%^"+caster->query_cap_name()+" gathers the glory that is Torm from around him, forming it into a great bolt of Glory, then hurls it at "+target->query_cap_name()+"!", target );
    }
    if (!"/daemon/saving_d"->saving_throw(target, "spell")) {
        tell_object(target, "%^BOLD%^The bolt of glory strikes your "+target_limb+" throwing you back.");
        tell_room(environment(caster), "%^BOLD%^"+target->query_cap_name()+" is struck by the Bolt of Glory in the "+target_limb+" throwing him to the ground!", ({target}) );
        damage_targ(target, target_limb, damage);
    } else {
        tell_object(target, "%^BOLD%^You dive away from the Bolt of Glory, the wake of its power passing through you.");
        tell_room(environment(caster), "%^BOLD%^"+target->query_cap_name()+" barely dives from the Bolt of Glory, the shockwave of its power throwing "+target->query_objective()+" around", ({target}) );
        damage_targ(target, target_limb, to_int(damage / 2) );
    }
    dest_effect();
}

void dest_effect() {
    ::dest_effect();
    TO->remove();
}

int help() {
    write(
@EndText
Spell  : Bolt of Glory
Level  : 6th Level
Sphere : Combat
Deity  : Torm
Syntax : chant bolt of glory on <target>

This spell will allow you to gather the power and glory that is Torm himself, and form it into a great bolt of power to be thrown at your enemies.


EndText
);
    return 1;
}

string query_cast_string() {
   return caster->query_cap_name()+" starts to wave "+caster->query_possessive()+" arms in the air as if gathering something to "+caster->query_possessive()+" body.";
}
