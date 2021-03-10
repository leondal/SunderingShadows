#include <spell.h>
#include <daemons.h>

inherit SPELL;

int clevel,effect,damage,x;
string target_limb;
object caster,target,place,victim,*allies;

void dest_effect();
void damage();

void create() {
    ::create();
    set_spell_name("blast of force");
    set_spell_level(5);
    set_spell_type("priest");
    set_spell_sphere("combat");
    set_diety("auppenser");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
}

void spell_effect(int prof) {
    caster = CASTER;
    target = TARGET;
    place = PLACE;
    clevel = CLEVEL;

    if (!present(target,environment(caster))) {
        tell_object(caster,"%^BOLD%^Your target is not in this area.\n");
        dest_effect();
        return 1;
    }
    allies = ({});
    if (target->query_party())
        allies += PARTY_D->query_party_members(target->query_party());
    else
        allies += ({ target});
    tell_object(target, "%^BOLD%^%^CYAN%^"+caster->QCN+" fans out "+
       ""+caster->QP+" hands and blasts a wave of %^WHITE%^pure "+
       "force %^CYAN%^right at you!");
    tell_object(caster, "%^BOLD%^%^CYAN%^You fan out "+
       "your hands and blast a wave of %^WHITE%^pure "+
       "force %^CYAN%^right at "+target->QCN+"!");
    tell_room(place, "%^BOLD%^%^CYAN%^"+caster->QCN+" fans out "+
       ""+caster->QP+" hands and blasts a wave of %^WHITE%^pure "+
       "force %^CYAN%^right at "+target->QCN+"!", ({caster, target}) );
    for (x=0;x < sizeof(allies);x++)
       if (((!random(3)) || (target == allies[x])) && present(allies[x],environment(caster)))
            damage();
    dest_effect();
}

void damage() {
    string before, after, *immunities;
    int i;

    damage = roll_dice(clevel,5);
    damage += 1 + random(3);
    if (SAVING_D->saving_throw(allies[x], "spell")) {
        tell_room(place, "%^BOLD%^"+allies[x]->QCN+" dodges the wave "+
           "of force!", allies[x] );
        tell_object(allies[x], "%^BOLD%^You dodge the majority of the wave "+
           "of force!");
        damage_targ(allies[x], "torso", to_int(damage / 2) );
    } else {
        tell_room(place, "%^BOLD%^"+allies[x]->QCN+" is blasted by "+
           "the wave of force!", allies[x] );
        tell_object(allies[x], "%^BOLD%^The wave of force blasts into you!");
        damage_targ(allies[x], "torso", damage);
    }
    return;
}

void dest_effect() {
    ::dest_effect();
    destruct(TO);
}

int help() {
    write(

@EndText
Spell  : Blast of Force
Level  : 5th Level
Sphere : Combat
Deity  : Auppenser
Syntax : chant blast of force on <target>

To cast this spell, the priest fans out his hands, calling upon 
Auppenser's aid.  The priest produces a blast of pure force in 
the form of a wave that strikes the target and possibly his 
allies.

EndText
);
    return 1;
}

string query_cast_string() {
   return caster->query_cap_name()+" fans out "+caster->query_possessive()+" hands and begins to chant to Auppenser.";
}
