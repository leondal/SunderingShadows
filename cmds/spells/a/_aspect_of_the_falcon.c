/*
  _aspect_of_the_falcon.c

  +3 to perception skill

  -- Tlaloc -- 7.11.20
*/

#include <std.h>
#include <magic.h>
#include <clock.h>

inherit SPELL;

int bonus;

void create()
{
    ::create();

    set_spell_name("aspect of the falcon");
    set_spell_level( ([ "ranger" : 1, ]) );
    set_spell_sphere("divination");
    set_syntax("cast CLASS aspect of the falcon");
    set_damage_desc("half of clevel to perception skill");
    set_description("By attuning yourself to the skies above, you gain a +4 bonus to your perception.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_helpful_spell(1);
}

int preSpell()
{
    target = caster;

    if(target->query_property("aspect_of_the_falcon"))
    {
        tell_object(target, "You are already under the influence of Aspect of the Falcon.");
        return 0;
    }

    return 1;
}

void spell_effect()
{
    target = caster;

    spell_successful();

    tell_object(caster, "%^GREEN%^You close your eyes and attune yourself to the skies above.%^RESET%^");
    tell_room(place, "%^GREEN%^" + sprintf("%s closes %s eyes and seems to meditate.",caster->query_name(),caster->query_possessive()) + "%^RESET%^", caster);

    bonus = 4;
    caster->add_skill_bonus("perception", bonus);

    caster->set_property("spelled", ({ this_object() }) );
    caster->set_property("aspect_of_the_falcon", 1);
    addSpellToCaster();

    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void dest_effect()
{
    if(objectp(target))
    {
        target->add_skill_bonus("perception", -bonus);
        target->remove_property("spelled", ({ this_object() }) );
        tell_object(target, "%^GREEN%^You feel your attunement to the skies above slip away.%^RESET%^");
        target->remove_property("aspect_of_the_falcon");
    }
    ::dest_effect();
    if(objectp(this_object()))
        this_object()->remove();
}
