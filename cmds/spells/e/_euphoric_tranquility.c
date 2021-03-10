#include <spell.h>
inherit SPELL;

void create() {
    ::create();
    set_spell_name("euphoric tranquility");
    set_spell_level(([ "mage" : 8, "cleric" : 8, "druid" : 8, "bard" : 6 ]));
    set_spell_sphere("enchantment_charm");
    set_syntax("cast CLASS euphoric tranquility on TARGET");
    set_damage_desc("stop combat for target");
    set_description("A creature under the effect of this enchantment enters a state of euphoria. The target treats all creatures as dear friends and abhors violence, but it may rise up to protect itself if violence is perpetrated against it.");
    set_save("will");
    set_target_required(1);
    mental_spell(1);
}

string query_cast_string()
{
    return "%^MAGENTA%^"+caster->QCN+" draws a scintillating pattern.%^RESET%^";
}

spell_effect(int prof)
{
    spell_successful();
    if(!objectp(target))
        return;
    tell_object(caster,"%^MAGENTA%^You throw the pattern at "+target->QCN+".%^RESET%^");
    tell_room(place,"%^MAGENTA%^"+caster->QCN+" throws the pattern at "+target->QCN+".%^RESET%^",({caster,target}));
    tell_object(target,"%^MAGENTA%^"+caster->QCN+" throws the pattern into your face.%^RESET%^");

    if(!(do_save(target,-2)||mind_immunity_damage(target, "default")))
    {
        object attackers = target->query_attackers();
        object attacker;
        foreach(attacker in attackers)
        {
            target->remove_attacker(attacker);
            attacker->remove_attacker(target);
        }
        tell_room(place,"%^BOLD%^%^MAGENTA%^"+target->QCN+" ceases all attacks, appearing to be tranquil for the moment..%^RESET%^");
    }
    else
    {
        tell_room(place,"%^MAGENTA%^"+target->QCN+" shakes it off, whatever that was.%^RESET%^",target);
        tell_object(target,"%^MAGENTA%^...but you manage to resist the euphoria..%^RESET%^");
    }
    TO->dest_effect();
}
