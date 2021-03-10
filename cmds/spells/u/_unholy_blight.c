#include <std.h>
#include <daemons.h>
#include <spell.h>
#include <magic.h>


inherit SPELL;

void create() {
    ::create();
    set_spell_name("unholy blight");
    set_spell_level(([ "inquisitor" : 4, "cleric" : 4 ]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS unholy blight");
    set_damage_desc("divine, sickened");
    set_description("This spell smites everyone in sight with unholy power. Evil and neutral creatures will suffer only the half of damage, and so will those who manage to will the spell off. Good creatures that failed the will save will become sickened for clevel/12+1 rounds.

%^BOLD%^%^RED%^See also:%^RESET%^ status effects");
    set_verbal_comp();
    set_somatic_comp();
    splash_spell(3);
    evil_spell(1);
    set_save("will");
}

void spell_effect(int prof){
    object *attackers;
    int i,admg, align;
    attackers = target_selector();
    attackers -= caster->query_followers();

    tell_room(place,"%^BOLD%^%^BLACK%^"+caster->QCN+" raises hand and releases waves of unholy power!%^RESET%^");
    if(!sizeof(attackers)){
        tell_object(caster,"%^BOLD%^%^BLACK%^The area is washed in unholy power, but nothing happens.%^RESET%^");
        dest_effect();
        return;
    }

    for(i=0;i<sizeof(attackers);i++)
    {
        if(!objectp(attackers[i]))
            continue;
        if(attackers[i]->is_undead())
            continue;
        admg=sdamage;
        align = attackers[i]->query_alignment();
        if(do_save(attackers[i],0) ||
           !(align==1 && align==4 && align==7))
        {
            admg/=2;
        }
        else
        {
            object eff = "/std/effect/status/sickened"->apply_effect(attackers[i],clevel/8+1);
            if(objectp(eff))
                eff->set_spell();
        }
        tell_object(attackers[i],"%^BLACK%^%^BOLD%^Your soul is shaken with the unholy smite!%^RESET%^");
        damage_targ(attackers[i],attackers[i]->return_target_limb(),admg,"divine");
    }
    spell_successful();
    dest_effect();
}

void dest_effect(){
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
