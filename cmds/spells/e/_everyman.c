/*
  _everyman.c

  Psion gained clevel / 4 to stealth

  -- Tlaloc -- 4.4.20
*/

#include <std.h>
#include <magic.h>

inherit SPELL;

int bonus;

void create()
{
    ::create();

    set_spell_name("everyman");
    set_spell_level( ([ "psion" : 2, "psywarrior" : 2 ]) );
    set_spell_sphere("clairsentience");
    set_syntax("cast CLASS everyman");
    set_bonus_type("circumstance");
    set_damage_desc("Clevel / 4 to stealth skill");
    set_description("By meditating on your appearance and mannerisms, you can blend into your surroundings.");
    set_verbal_comp();
    set_arg_needed();
    set_helpful_spell(1);
}

int preSpell()
{
    target = caster;

    /*
    if(target->query_property("everyman"))
    {
        tell_object(target, "You are already under the influence of Everyman.");
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
    caster->add_skill_bonus("stealth", bonus);

    caster->set_property("spelled", ({ this_object() }) );
    //caster->set_property("everyman", 1);
    addSpellToCaster();

    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 2;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void dest_effect()
{
    if(objectp(target))
    {
        target->add_skill_bonus("stealth", -bonus);
        target->remove_property("spelled", ({ this_object() }) );
        tell_object(target, "%^CYAN%^You feel your command of disguise fading away.%^RESET%^");
        //target->remove_property("everyman");
    }
    ::dest_effect();
    if(objectp(this_object()))
        this_object()->remove();
}
