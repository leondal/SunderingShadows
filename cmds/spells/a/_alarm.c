#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

#define ALARM "/d/magic/obj/alarm"
inherit SPELL;

object alarm;

void create()
{
    ::create();
    set_spell_name("alarm");
    set_spell_level(([ "bard" : 1, "inquisitor" : 1, "ranger" : 1, "mage" : 1 ]));
    set_spell_sphere("abjuration");
    set_syntax("cast CLASS alarm on [audible|mental]");
    set_description("You draw an invisible alarm rune on the ground. If the alarm detects anyone in the room besides you and your followers it will convey either a telepathic message directly into your mind, or a loud pop to nearby rooms. You can have as many alarms as you need, but after awhile the magic in them will dissipate.");
    set_arg_needed();
    set_helpful_spell(1);
}

void spell_effect()
{
    tell_object(caster, "%^RESET%^%^CYAN%^You touch the ground, inscribing an alarm rune onto it.");
    tell_room(place, "%^RESET%^" + caster->QCN + " touches the ground.", ({ caster }));
    alarm = new(ALARM);
    alarm->move(place);
    alarm->set_property("spell", TO);
    alarm->set_property("spelled", ({ TO }));
    alarm->setup(caster, TO, arg);
    spell_successful();
    addSpellToCaster();
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 6;
    set_end_time();
    call_out("dest_effect", spell_duration);
}

void dest_effect()
{
    if (objectp(alarm)) {
        alarm->remove_alarm();
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
