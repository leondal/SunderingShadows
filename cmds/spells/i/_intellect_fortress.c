/*
  _intellect_fortress.c

  Gives the psion immunity to fear.

  -- Tlaloc -- 5.9.21
*/

#include <std.h>
#include <magic.h>

inherit SPELL;

void create()
{
    ::create();

    set_spell_name("intellect fortress");
    set_spell_level( ([ "psion" : 4, ]) );
    set_spell_sphere("telepathy");
    set_syntax("cast CLASS intellect fortress");
    set_damage_desc("fear immunity");
    set_description("Using the power of pure logic, the manifester of this power suppresses all attempts at causing him fear.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_helpful_spell(1);
}

int preSpell()
{
    target = caster;

    if(target->query_property("intellect fortress"))
    {
        tell_object(target, "You are already under the influence of intellect fortress.");
        return 0;
    }

    return 1;
}

void spell_effect()
{
    target = caster;

    spell_successful();

    tell_object(caster, "%^CYAN%^You touch your forehead with a glowing index finger establish a mental fortress around your mind.%^RESET%^");
    tell_room(place, "%^CYAN%^" + sprintf("%s touches %s forehead with a glowing blue index finger.",caster->query_cap_name(),caster->query_possessive()) + "%^RESET%^", caster);

    caster->set_property("spelled", ({ this_object() }) );
    caster->set_property("intellect fortress", 1);
    addSpellToCaster();

    spell_duration = 300 + (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 2;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void dest_effect()
{
    if(objectp(target))
    {
        target->remove_property("spelled", ({ this_object() }) );
        tell_object(target, "%^CYAN%^You feel your intellect fortress slip away.%^RESET%^");
        target->remove_property("intellect fortress");
    }
    ::dest_effect();
    if(objectp(this_object()))
        this_object()->remove();
}
