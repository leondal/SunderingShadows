#include <spell.h>
inherit SPELL;

void create()
{
    ::create();
    set_spell_name("hellfire ray");
    set_spell_level(([ "mage" : 6, "cleric" : 6, "magus" : 6 ]));
    set_domains("evil");
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS hellfire ray on TARGET");
    set_damage_desc("half fire, half divine");
    set_description("A blast of hellfire blazes from your hands. Half the damage is fire damage, but the other half results directly from unholy power and is therefore not subject to being reduced by fire resistance. This ray deals damage directly to target soul so good characters will never use it.");
    evil_spell(1);
    set_verbal_comp();
    set_somatic_comp();
    set_silent_casting(1);
    set_target_required(1);
}

string query_cast_string()
{
    return "%^BOLD%^%^WHITE%^"+caster->QCN+" crushes a %^BLACK%^brimstone%^WHITE%^ while chanting in infernal tongues.%^RESET%^";
}

spell_effect(int prof)
{
    spell_successful();
    if (interactive(caster))
    {
        tell_object(caster,"%^BOLD%^%^WHITE%^You open your hands and release %^RED%^ray of %^ORANGE%^hell%^BLACK%^fire%^WHITE%^ at "+target->QCN+"!");
        tell_room(place,"%^BOLD%^%^WHITE%^"+caster->QCN+" opens "+caster->QP+" hands and releases %^RED%^ray of %^ORANGE%^hell%^BLACK%^fire%^WHITE%^ at "+caster->QP+"!", ({caster}) );
        tell_object(target,"%^BOLD%^%^WHITE%^It burns your very soul!%^RESET%^");
    }
    damage_targ(target, target->return_target_limb(), sdamage/2,"fire");
    damage_targ(target, target->return_target_limb(), sdamage/2,"divine");
    TO->dest_effect();
}

void dest_effect()
{
    ::dest_effect();
    if(objectp(TO))
        TO->remove();
}
