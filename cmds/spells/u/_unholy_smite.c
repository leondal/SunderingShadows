#include <std.h>
#include <daemons.h>
#include <spell.h>
#include <magic.h>


inherit SPELL;

void create() {
    ::create();
    set_spell_name("unholy smite");
    set_spell_level(([ "cleric" : 4, "inquisitor" : 4 ]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS unholy smite");
    set_damage_desc("untyped on neutral and good");
    set_description("You draw down holy power to smite your enemies, possibly blinding them. Only good and neutral creatures are harmed by the spell, evil creatures are unaffected..");
    set_verbal_comp();
    set_somatic_comp();
    splash_spell(3);
    set_save("will");
}

string query_cast_string() {
    return "%^BOLD%^%^BLUE%^"+caster->QCN+" proclaims a divine prayer of smiting.";
}

void spell_effect(int prof){
    object *attackers;
    int i,admg;
    attackers = target_selector();

    tell_room(place,"%^BOLD%^%^CYAN%^"+caster->QCN+" raises hand and dark flames burst out of "+caster->QO+" in all directions!%^RESET%^");
    if(!sizeof(attackers))
    {
        tell_object(caster,"%^BOLD%^%^BLUE%^The area is washed with flames but nothing else happens.%^RESET%^");
        dest_effect();
        return;
    }

    for(i=0;i<sizeof(attackers);i++)
    {
        int align = attackers[i]->query_alignment();
        if(!objectp(attackers[i]))
            continue;
        if(!(align %3))
            continue;
        admg=sdamage;
        if(do_save(attackers[i]),-2)
        {
            admg/=2;
        }
        else
        {
            tell_object(attackers[i],"%^BOLD%^%^BLUE%^The darknes covers your eyes, blinding you!%^RESET%^");
            attackers[i]->set_temporary_blinded(3);
        }
        tell_object(attackers[i],"%^BOLD%^%^BLUE%^Your soul withers in the darkn flames!%^RESET%^");
        damage_targ(attackers[i],attackers[i]->return_target_limb(),admg,"untyped");
    }
    spell_successful();
    dest_effect();
}

void dest_effect(){
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
