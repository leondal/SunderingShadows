/*
  _mindwipe.c
  
  Psychic version of enervation.
  
  -- Tlaloc --
*/

#include <std.h>
#include <magic.h>

inherit SPELL;

void create() {
    ::create();
    set_spell_name("mindwipe");
    set_spell_level(([ "psion" : 4 ]));
    set_spell_sphere("telepathy");
    set_syntax("cast CLASS mindwipe on TARGET");
    set_damage_desc("1d4 negative levels to living for 1d20 rounds");
    set_description("You erase a portion of the targets mind and experiences, inflicting 1d4 negative levels on them.");
    mental_spell();
    set_save("will");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
}

string query_cast_string()
{
    return caster->QCN + " reaches out with " + caster->QP + " mind.\n";
}

void spell_effect(int prof)
{
    int round_duration;
    int power;
    int i;
    
    if(!target)
        return;
    
    spell_successful();

    power = roll_dice(1, 4);
    round_duration = roll_dice(1, 20);
    
    tell_object(caster, "%^CYAN%^You reach deep into " + target->QCN + "'s mind and attempt to wipe their memories!%^RESET%^");
    tell_object(target, "%^CYAN%^" + caster->QCN + " attempts to reach into your mind!%^RESET%^");
    
    if(!do_save(target, 0))
    {
        tell_object(caster, target->QCN + " resists your mindwipe!%^RESET%^");
        tell_object(target, "You resist the mindwipe!");
        return;
    }
    
    tell_object(caster,"%^BOLD%^%^CYAN%^You cause serious damage to " + target->QCN + "'s mind.%^RESET%^");
    tell_object(target,"%^BOLD%^CYAN%^Your mind is seriously damaged, destroying experiences and memories!.%^RESET%^");

    "/std/effect/status/negative_level"->apply_effect(target, round_duration, power);
    spell_kill(target, caster);
}
