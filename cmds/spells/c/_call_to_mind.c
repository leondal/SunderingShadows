/*
  _call_to_mind.c

  Half CL to Academics Skill

  -- Tlaloc -- 3.28.20
*/

#include <std.h>
#include <magic.h>

inherit SPELL;

int bonus;

void create()
{
    ::create();

    set_spell_name("call to mind");
    set_spell_level( ([ "psion" : 1, ]) );
    set_spell_sphere("clairsentience");
    set_syntax("cast CLASS call to mind");
    set_damage_desc("half of clevel to academics skill");
    set_description("By meditating on a subject, you can recall natural memories and knowledge otherwise inaccessible to you.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_helpful_spell(1);
}

int preSpell()
{
    target = caster;

    if(target->query_property("call_to_mind"))
    {
        tell_object(target, "You are already under the influence of Call to Mind.");
        return 0;
    }

    return 1;
}

void spell_effect()
{
    target = caster;

    spell_successful();

    tell_object(caster, "%^CYAN%^You touch your forehead with a glowing index finger and feel a rush of knowledge flow in.%^RESET%^");
    tell_room(place, "%^CYAN%^" + sprintf("%s touches %s forehead with a glowing blue index finger.",caster->query_cap_name(),caster->query_possessive()) + "%^RESET%^", caster);

    bonus = clevel / 2 + 1;
    caster->add_skill_bonus("academics", bonus);

    caster->set_property("spelled", ({ this_object() }) );
    caster->set_property("call_to_mind", 1);
    addSpellToCaster();

    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 2;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void dest_effect()
{
    if(objectp(target))
    {
        target->add_skill_bonus("academics", -bonus);
        target->remove_property("spelled", ({ this_object() }) );
        tell_object(target, "%^CYAN%^You feel your academic insights slipping away.%^RESET%^");
        target->remove_property("call_to_mind");
    }
    ::dest_effect();
    if(objectp(this_object()))
        this_object()->remove();
}
