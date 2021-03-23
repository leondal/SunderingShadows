#include <std.h>
#include <daemons.h>
#include <spell.h>
#include <magic.h>


inherit SPELL;

void create() {
    ::create();
    set_spell_name("sirocco");
    set_spell_level(([ "mage" : 6, "druid" : 6, "oracle" : 6, "magus" : 6, "cleric" : 6 ]));
    set_mystery( ({ "solar", "wind" }) );
    set_domains(({"air"}));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS sirocco");
    set_damage_desc("bludgeoning");
    set_description("A blast of furnace-hot wind blasts downward, smashing them with power of the blast and knocking them prone.");
    splash_spell(3);
    set_save("fort");
}

void spell_effect(int prof){
    object *attackers;
    int i,admg;
    attackers = target_selector();

    tell_room(place,"%^BLUE%^%^BOLD%^"+caster->QCN+" raises hand and releases waves of hot winds in all directions!%^RESET%^");
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
            attackers[i]->set_tripped(roll_dice(1,3),"%^BOLD%^You are struggling to regain your footing!%^RESET%^",4);
        tell_object(attackers[i],"%^BLUE%^%^BOLD%^Hot winds slam into you!%^RESET%^");
        damage_targ(attackers[i],attackers[i]->return_target_limb(),admg,"bludgeoning");
    }
    spell_successful();
    dest_effect();
}

void dest_effect(){
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
