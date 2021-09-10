#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

void create()
{
    ::create();
    set_spell_name("fold space");
    set_spell_level(([ "psion" : 4, "psywarrior" : 4 ]));
    set_spell_sphere("psychoportation");
    set_syntax("cast CLASS fold space to <location>");
    set_description("This power will move the psion from his current location to one he has previously memorized.  The "
                    "psion merely concentrates, setting his sights on the place he would like to be, and his mind manipulates time and space "
                    "to place him there.  An example of the power's usage is <remember here as cave>.  Then later on, the psion would type, "
                    "<cast psion fold space to cave>.  Again, you may also <unremember cave> to forget that particular location.\nThis spell must be cast while at peace.\nSee also: "
                    "remember, unremember, recall");
    set_verbal_comp();
    set_arg_needed();
    set_casting_time(1);
    set_peace_needed(1);
    set_helpful_spell(1);
}

string check_error(string file, int prof)
{
    return file;
}

string query_cast_string()
{
    return "%^CYAN%^" + caster->QCN + " grows still, concentrating carefully.";
}

void spell_effect(int prof)
{
    object endplace;

    if (sizeof(caster->query_attackers())) {
        tell_object(caster, "Combat distracts you from your spell!");
        tell_room(place, caster->QCN + " is distracted by combat, spell fails.");
        dest_effect();
        return;
    }
    tell_object(caster, "%^RESET%^%^GREEN%^You ready your destination " +
                "in your mind, focusing on bringing it to you.");
    tell_room(place, "%^RESET%^%^GREEN%^" + caster->QCN + "'s eyes take " +
              "on a faraway look as " + caster->QS + " seems to grow a bit " +
              "insubstantial!", caster);
    if (!(endplace = "/std/magic/teleport"->teleport_object(caster, caster, arg, clevel))) {
        tell_object(caster, "You sense something blocking your " +
                    "passage and the power backfires.");
        tell_room(place, caster->QCN + " " +
                  "looks startled.", caster);
        damage_targ(caster, caster->return_target_limb(), sdamage, "mental");
        dest_effect();
        return;
    }

    spell_successful();

    caster->clear_followers();
    tell_room(endplace, "%^RESET%^%^GREEN%^An outline of a figure appears near you.", caster);
    dest_effect();
    return;
}

void dest_effect()
{
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
