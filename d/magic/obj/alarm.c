#include <std.h>
#include <magic.h>
#include <daemons.h>
inherit MONSTER;

object caster;
string alarm_type = "audible";
object spell;
object* obs_livings;

void create()
{
    ::create();
    set_name("alarm sign");
    set_id(({ "alarm_999" }));

    set_property("no detect", 1);

    set_short(0);
    set_invis();
    add_limb("body", "", 0, 0, 0);
}

void setup(object invoker, object invspell, string atype)
{
    caster = invoker;
    alarm_type = atype;
    obs_livings = select_livings();
    call_out("alarm_observe", ROUND_LENGTH);
}


void alarm_observe()
{
    if (!objectp(caster)) {
        if (objectp(query_property("spell"))) {
            query_property("spell")->dest_effect();
            return;
        }
        remove_call_out("alarm_observe");
        TO->remove();
    }else {

        object * livings;
        object * new_livings;

        new_livings = select_livings();
        livings = new_livings - obs_livings;

        if (objectp(caster)) {
            if (sizeof(livings)) {
                if (alarm_type == "mental") {
                    tell_room(caster, "%^CYAN%^An alarm set in " + ENV(TO)->query_short() + " had been set off.%^RESET%^");
                    remove_alarm();
                } else {
                    if (alarm_type == "audible") {
                        message("info", "%^BOLD%^%^CYAN%^You hear a loud pop.%^RESET%^", nearbyRoom(ENV(TO), 2));
                    }
                    remove_alarm();
                }
            }
        }
    }
    call_out("alarm_observe", ROUND_LENGTH);
}

int die()
{
    remove_hound();
}

void remove_alarm()
{
    remove_call_out("alarm_observe");
    if (objectp(caster) &&
        objectp(ETO)) {
        tell_object(caster, "%^CYAN%^You concentration releases as alarm in " + ETO->query_short() + " fades.%^RESET%^");
        if (objectp(spell)) {
            spell->dest_effect();
        }
    }
    destruct(TO);
}
