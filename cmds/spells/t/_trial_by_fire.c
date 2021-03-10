#include <std.h>
#include <daemons.h>
#include <spell.h>
#include <magic.h>


inherit SPELL;

void create() {
    ::create();
    set_spell_name("trial by fire");
    set_spell_level(([ "inquisitor" : 3, "cleric" : 3, "paladin" : 3 ]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS trial by fire");
    set_damage_desc("half fire, half divine on unfaithful");
    set_description("You test a creature's purity of convictions by exposing it to a sheet of divine fire. Unless they are of the same faith as you they'll take damage. Half of this damage comes directly from the divine and can't be reduced.");
    set_verbal_comp();
    set_somatic_comp();
    splash_spell(3);
}

string query_cast_string() {
    return "%^RED%^"+caster->QCN+" hums a prayer, "+caster->QP+" words are fire.";
}

void spell_effect(int prof){
    object *attackers;
    int i,admg;
    attackers = caster->query_attackers();
    attackers = filter_array(attackers,(:$1->query_diety()!=$2->query_diety():),caster);

    tell_room(place,"%^RED%^"+caster->QCN+" raises hand and releases waves of holy fire!%^RESET%^");
    if(!sizeof(attackers)){
        tell_object(caster,"%^BOLD%^%^RED%^The area is washed in holy fire but nobody is affected.%^RESET%^");
        dest_effect();
        return;
    }

    for(i=0;i<sizeof(attackers);i++)
    {
        if(!objectp(attackers[i]))
            continue;
        admg=sdamage;
        tell_object(attackers[i],"%^RED%^You're burned with divine fire!%^RESET%^");
        tell_room(place,"%^RED%^"+attackers[i]->QCN+" is burned with divine fire!%^RESET%^",attackers[i]);
        damage_targ(attackers[i],attackers[i]->return_target_limb(),admg/2,"fire");
        damage_targ(attackers[i],attackers[i]->return_target_limb(),admg/2,"divine");
    }
    spell_successful();
    dest_effect();
}

void dest_effect(){
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
