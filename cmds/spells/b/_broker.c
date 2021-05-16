/*
  _broker.c

  Psion gained clevel / 4 to influence

  -- Tlaloc -- 3.28.20
*/

#include <std.h>
#include <magic.h>

inherit SPELL;

int bonus;

void create()
{
    ::create();

    set_spell_name("broker");
    set_spell_level( ([ "psion" : 1, ]) );
    set_spell_sphere("clairsentience");
    set_bonus_type("circumstance");
    set_syntax("cast CLASS broker");
    set_damage_desc("Clevel / 4 to influence skill");
    set_description("By meditating on your character and mannerisms, you can become more influential towards others.");
    set_verbal_comp();
    set_arg_needed();
    set_helpful_spell(1);
}

int preSpell()
{
    target = caster;

    /*
    if(target->query_property("broker"))
    {
        tell_object(target, "You are already under the influence of Broker.");
        return 0;
    }
    */

    return 1;
}

void spell_effect()
{
    target = caster;

    spell_successful();

    tell_object(caster, "%^CYAN%^You touch your forehead with a glowing index finger and feel a rush of influence flow in.%^RESET%^");
    tell_room(place, "%^CYAN%^" + sprintf("%s touches %s forehead with a glowing blue index finger.",caster->query_cap_name(),caster->query_possessive()) + "%^RESET%^", caster);

    bonus = clevel / 4 + 1;
    caster->add_skill_bonus("influence", bonus);

    caster->set_property("spelled", ({ this_object() }) );
    //caster->set_property("broker", 1);
    addSpellToCaster();

    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 2;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void dest_effect()
{
    if(objectp(target))
    {
        target->add_skill_bonus("influence", -bonus);
        target->remove_property("spelled", ({ this_object() }) );
        tell_object(target, "%^CYAN%^You feel your command of influence fading away.%^RESET%^");
        //target->remove_property("broker");
    }
    ::dest_effect();
    if(objectp(this_object()))
        this_object()->remove();
}
