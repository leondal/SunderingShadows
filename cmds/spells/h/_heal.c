// --==** /cmds/priest/_heal.c **==--
// Modified by Pator@ShadowGate
// August 25 1995
#include <priest.h>

inherit SPELL;

void create()
{
    ::create();
    set_spell_name("heal");
    set_spell_level(([ "cleric" : 6,"inquisitor":6,"oracle":6 ]));
    set_mystery("life");
    set_domains("renewal");
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS heal on TARGET");
    set_damage_desc("positive energy");
    set_affixed_spell_level(6);
    set_description("%^RESET%^This spell will channel huge amount of positive energy into target and will allow the caster to cure massive amount damage from wounds and diseases. This spell will cure status effects such as blinded, confused, dazzled, paralyzed, fatigued, exhausted, sickened and will cure negative levels.

%^BOLD%^%^RED%^See also:%^RESET%^ heal *player commands, status effects");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_casting_time(15);
    set_helpful_spell(1);
}


string query_cast_string()
{
    string cast;
    if (interactive(caster))
    {
        cast = "%^BOLD%^%^WHITE%^"+caster->QCN+" folds "+caster->QP+
            " hands as "+caster->QS+" prays for a divine spell!\n";
    }
    else
    {
        cast = "%^BOLD%^%^WHITE%^"+caster->QCN+" calls for a divine spell!\n";
    }
    return "\n"+cast;
}


spell_effect(int prof)
{
    int rnd;

    set_helpful_spell(1);
    if(target->query_property("negative energy affinity"))
        set_helpful_spell(0);
    if (interactive(caster))
    {
        // CAST UPON ONESELF
        if ( caster == target )
        {
            tell_object(caster, "%^WHITE%^%^BOLD%^You reach out and channel energy at yourself.");
            tell_room(place, "%^WHITE%^%^BOLD%^"+YOU+" reaches out and channels energy at "+caster->QO+"self.", ({ caster, target}) );
        }
        else
        {
            tell_object(caster, "%^WHITE%^%^BOLD%^You reach out and channel energy at "+target->QCN+".");
            tell_room(place, "%^WHITE%^%^BOLD%^"+YOU+" channels energy at "+target->QCN+".",({ caster}) );
        }
    }
    else
    {
        // OBJECT CALLS HEAL
        tell_room(environment(caster), "%^WHITE%^%^BOLD%^"+caster->QCN+" sends a beam of energy at "+target->QCN+".",({ caster, target }) );
        tell_object(target, "%^WHITE%^%^BOLD%^"+caster->QCN+" sends a beam of energy at you.");
    }

    rnd = sdamage * 7/6;
    damage_targ(target, target->return_target_limb(), rnd, "positive energy");

    if(query_spell_name()=="heal")
        if(member_array(target,caster->query_attackers())==-1)
            "/std/magic/cleanse"->cleanse(target);

    dest_effect();
}

void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
