#include <priest.h>

inherit SPELL;

void create()
{
    ::create();
    set_spell_name("repair undead");
    set_spell_level(([ "mage" : 1, ]));
    set_affixed_spell_level(2);
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS repair undead on TARGET");
    set_damage_desc("negative energy on undead");
    set_description("This spell will channel huge amount of negative energy into target and will repair them if they are undead. This spell won't affect the living, unless they can be healed by negative energy.");
    set_save("will");
    set_target_required(1);
    set_helpful_spell(1);
}


string query_cast_string()
{
    string cast;
    cast = "%^BOLD%^%^BLACK%^"+caster->QCN+" folds "+caster->QP+" hands as "+caster->QS+" spells an incantation!\n";
    return "\n"+cast;
}


spell_effect(int prof)
{
    int rnd;

    set_helpful_spell(1);
    if(!target->query_property("negative energy affinity"))
    {
        tell_room(place,"%^BOLD%^%^BLACK%^Nothing happens.");
        dest_effect();
        return;
    }
    if (interactive(caster))
    {
        if ( caster == target )
        {
            tell_object(caster, "%^BOLD%^%^BLACK%^You reach out and channel fell energy at yourself.");
            tell_room(place, "%^BOLD%^%^BLACK%^"+YOU+" channels fell energy at "+caster->QO+"self.", ({ caster, target}) );
        }
        else
        {
            tell_object(caster, "%^BOLD%^%^BLACK%^You channel fell energy at "+target->QCN+".");
            tell_room(place, "%^BOLD%^%^BLACK%^"+YOU+" channels fell energy at "+target->QCN+".",({ caster}) );
        }
    }
    else
    {
        tell_room(environment(caster), "%^BOLD%^%^BLACK%^"+caster->QCN+" sends a beam of energy to "+target->QCN+".",({ caster, target }) );
        tell_object(target, "%^BOLD%^%^BLACK%^"+caster->QCN+" sends a beam of fell energy at you.");
    }

    rnd = sdamage * 7/6;
    damage_targ(target, target->return_target_limb(), rnd, "negative energy");

    dest_effect();
}
