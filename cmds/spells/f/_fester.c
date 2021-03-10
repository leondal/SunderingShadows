#include <std.h>
#include <magic.h>
inherit SPELL;

int lower;

void create()
{
    ::create();
    set_spell_name("fester");
    set_spell_level(([ "inquisitor" : 3 ]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS fester on TARGET");
    set_damage_desc("resistance to healing spells");
    set_description("Necrotic energy permeates the target, blocking some of energy flow, impeding their healing abilities.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
}

string query_cast_string()
{
    return "%^MAGENTA%^"+caster->QCN+" proclaims and incantation, darkness forms behind "+caster->QO+".";
}

int preSpell()
{
    if (target->query_property("fester"))
    {
        tell_object(caster,"%^BOLD%^The spell is repelled forcibly.");
        return 0;
    }
    return 1;
}

void spell_effect()
{
    tell_room(place,"%^MAGENTA%^You watch as bolt of darkness hits"+target->QCN+".",({caster,target}));
    tell_object(target,"%^MAGENTA%^You feel cold as bolt of darkness released by "+caster->QCN+" reaches you.");
    tell_object(caster,"%^MAGENTA%^You point a finger at "+target->QCN+" and release bolt of darkness.");

    if (target->query_property("fester"))
    {
        tell_object(caster,"%^BOLD%^The spell is repelled forcibly.");
        dest_effect();
        return;
    }

    tell_room(place,"%^MAGENTA%^The place gets a little cold...");

    lower = sdamage;

    target->set_property("fester",lower / 2);

    target->set_property("spelled", ({TO}) );
    addSpellToCaster();
    spell_duration = (clevel / 10 + 1) * ROUND_LENGTH;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void dest_effect()
{
    if(objectp(target))
    {
        tell_object(target,"%^ORANGE%^The air grows warmer as your ability to heal returns.");
        target->remove_property("fester");
    }
    ::dest_effect();
    if(objectp(TO))
        TO->remove();
}
