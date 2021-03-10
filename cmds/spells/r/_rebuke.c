#include <std.h>
#include <daemons.h>
#include <spell.h>
#include <magic.h>


inherit SPELL;

void create() {
    ::create();
    set_spell_name("rebuke");
    set_spell_level(([ "inquisitor" : 4 ]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS rebuke");
    set_damage_desc("half sonic half divine");
    set_description("Your wrathful words cause physical harm to your enemies. Half of this damage is sonic damage, but the other half results directly from divine power and is therefore not subject to being reduced by resistance to sonic-based attacks. Rebuke is especially devastating to foes who worship your god, punishing them for offending your faith with additional damage.");
    set_verbal_comp();
    set_somatic_comp();
    splash_spell(3);
    set_save("fort");
}

string query_cast_string() {
    return "%^RED%^"+caster->QCN+" proclaims a wrathful incantation.";
}

void spell_effect(int prof){
    object *attackers;
    int i,admg;
    string mygod = caster->query_diety();
    attackers = target_selector();

    tell_room(place,"%^RED%^"+caster->QCN+"'s wrathful screams reach out to everyone in waves of power!%^RESET%^");
    if(!sizeof(attackers)){
        tell_object(caster,"%^RED%^Nobody seems to be affected.%^RESET%^");
        dest_effect();
        return;
    }

    for(i=0;i<sizeof(attackers);i++)
    {
        if(!objectp(attackers[i]))
            continue;

        admg=sdamage;
        if(attackers[i]->query_diety() == mygod)
            admg*=5/4;
        if(do_save(attackers[i]))
        {
            admg/=2;
        }
        tell_object(attackers[i],"%^RED%^Your entire body is shaken with wrathful scream!%^RESET%^");
        damage_targ(attackers[i],attackers[i]->return_target_limb(),admg/2,"sonic");
        damage_targ(attackers[i],attackers[i]->return_target_limb(),admg/2,"divine");
    }
    spell_successful();
    dest_effect();
}

void dest_effect(){
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
