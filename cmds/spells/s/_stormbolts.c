#include <std.h>
#include <daemons.h>
#include <spell.h>
#include <magic.h>


inherit SPELL;

void create() {
    ::create();
    set_spell_name("stormbolts");
    set_spell_level(([ "mage" : 8, "druid" : 8, "cleric" : 8 ]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS stormbolts");
    set_damage_desc("electricity");
    set_description("When you cast this spell, lightning spills forth from your body in all directions, harming everything in their path. Those unable to withstand the power of lightning will be briefly stunned.");
    splash_spell(2);
    set_save("fort");
}

void spell_effect(int prof){
    object *attackers;
    int i,admg;
    attackers = target_selector();

    tell_room(place,"%^BOLD%^%^ORANGE%^Bolts of lightning crackle the air, flying outwards from "+caster->QCN+"%^RESET%^");
    if(!sizeof(attackers)){
        dest_effect();
        return;
    }

    for(i=0;i<sizeof(attackers);i++)
    {
        if(!objectp(attackers[i]))
            continue;
        admg=sdamage;
        if(do_save(attackers[i]))
            admg/=2;
        else
            attackers[i]->set_paralyzed(8*2,"%^BOLD%^%^WHITE%^You're struggling with pain after the lightning stroke!%^RESET%^");
        tell_object(attackers[i],"%^WHITE%^%^BOLD%^The lightning burns through you.%^RESET%^");
        damage_targ(attackers[i],attackers[i]->return_target_limb(),admg,"electricity");
    }
    spell_successful();
    dest_effect();
}

void dest_effect(){
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
