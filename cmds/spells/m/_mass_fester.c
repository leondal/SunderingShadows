#include <std.h>
#include <magic.h>
inherit SPELL;

int lower;

object * atttracker = ({});

int is_curse()
{
    return 1;
}

void create()
{
    ::create();
    set_spell_name("mass fester");
    set_spell_level(([ "inquisitor" : 6 ]));
    set_spell_sphere("necromancy");
    set_affixed_spell_level(3);
    set_syntax("cast CLASS mass fester");
    set_damage_desc("resistance to healing spells");
    set_description("This spell functions exactly like fester, but affects all attackers.");
    set_verbal_comp();
    set_somatic_comp();
    splash_spell(3);
}

string query_cast_string()
{
    return "%^MAGENTA%^"+caster->QCN+" proclaims and incantation, darkness forms behind "+caster->QO+".";
}

void spell_effect()
{
    object * attackers;

    attackers = target_selector();

    tell_room(place,"%^MAGENTA%^You watch as tendrils of darkness hit everyone attacking "+caster->QCN+".",({caster}));
    tell_object(caster,"%^MAGENTA%^Tendrils of darkness caress your enemies.");

    lower = sdamage;

    foreach(target in attackers)
    {
        if (target->query_property("fester"))
            continue;

        tell_object(target,"%^MAGENTA%^You feel cold as tendrils of darkness released by "+caster->QCN+" reach you.");
        atttracker+=({target});

        target->set_property("fester",lower / 2);
        target->set_property("spelled", ({TO}) );
    }
    tell_room(place,"%^MAGENTA%^The place gets a little cold...");

    addSpellToCaster();
    spell_duration = (clevel / 10 + 1) * ROUND_LENGTH;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void dest_effect()
{
    foreach(target in atttracker)
    {
        if(objectp(target))
        {
            tell_object(target,"%^ORANGE%^The air grows warmer as your ability to heal returns.");
            target->remove_property("fester");
        }
    }
    ::dest_effect();
    if(objectp(TO))
        TO->remove();
}
