/*
  _rewind_age.c

  Psion reverses the negative effects of age

  -- Tlaloc -- 3.4.2021
*/

#include <std.h>
#include <magic.h>

inherit SPELL;

int bonus;

void create()
{
    ::create();

    set_spell_name("rewind age");
    set_spell_level( ([ "psion" : 6, ]) );
    set_spell_sphere("psychometabolism");
    set_discipline("egoist");
    set_syntax("cast CLASS rewind age");
    set_damage_desc("Removes penalties from age for duration");
    set_description("You ignore the physical detriments of age. This spell does not cause you to look younger, nor does it prevent you from dying of old age, but as long as the spell is in effect, you ignore the penalties to Strength, Dexterity, and Constitution that accrue once you become middle-aged. You retain the age-related bonuses to Intelligence, Wisdom, and Charisma while under the effects of this spell.");
    set_verbal_comp();
    set_arg_needed();
    set_helpful_spell(1);
}

int preSpell()
{
    target = caster;

    if(target->query_property("rewind age"))
    {
        tell_object(target, "You are already under the influence of Rewind Age.");
        return 0;
    }

    return 1;
}

void spell_effect()
{
    target = caster;

    spell_successful();

    tell_object(caster, "%^CYAN%^You touch your forehead with a glowing index finger and feel the effects of your age fade.%^RESET%^");
    tell_room(place, "%^CYAN%^" + sprintf("%s touches %s forehead with a glowing blue index finger.",caster->query_cap_name(),caster->query_possessive()) + "%^RESET%^", caster);

    caster->set_property("spelled", ({ this_object() }) );
    caster->set_property("rewind age", 1);
    addSpellToCaster();

    spell_duration = 180 + (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 2;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void dest_effect()
{
    if(objectp(target))
    {
        target->remove_property("spelled", ({ this_object() }) );
        tell_object(target, "%^CYAN%^You feel your age reversal disappearing.%^RESET%^");
        target->remove_property("rewind age");
    }
    ::dest_effect();
    if(objectp(this_object()))
        this_object()->remove();
}
