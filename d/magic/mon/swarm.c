#include <std.h>
inherit OBJECT;
object caster;
int level, cycle, total;
void setup_swarm(object obcaster, int oblevel);
void init()
{
    ::init();
    add_action("disperse_fun", "disperse");
}

void create()
{
    ::create();
    set_name("swarm");
    set_id(({ "swarm", "insects", "plague", "insect plague", "insect swarm" }));
    set_short("A swarm of insects");
    set_long(
        "This is a massive swarm of flying, stinging, biting, crawling and buzzing "
        "insects of numerous types and sizes. They attack everything within their area and "
        "seem impossible to stop or fight."
        );
    set_weight(100000);
    set_value(0);
    set_property("no animate", 1);
    call_out("sting", 2);
}

int disperse_fun(string str)
{
    if (!str) {
        notify_fail("Disperse what?\n");
        return 0;
    }
    if (str != "swarm") {
        notify_fail("Disperse what?\n");
        return 0;
    }
    if (TP != caster) {
        return 0;
    }
    write("%^GREEN%^You disperse the swarm of insects before you.%^RESET%^");
    say(
        "%^RESET%^%^GREEN%^The swarm suddenly scatters completely and disperses in numerous directions!"
        );
    caster->remove_property("swarm");
    TO->remove();
    return 1;
}

void setup_swarm(object obcaster, int oblevel)
{
    caster = obcaster;
    level = oblevel;
    cycle = 1;
    total = level * 10;
    tell_room(environment(caster), "%^GREEN%^"
              "A horde of numerous stinging and biting insects gather in the area!%^RESET%^"
              );
}

void sting()
{
    object here;
    object* inv;
    int max;
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        return;
    }
    if (!objectp(caster)) {
        return;
    }
    here = ETO;
    if (cycle > total) {
        tell_room(here,
                  "%^RESET%^%^GREEN%^The swarm suddenly scatters completely and disperses in numerous directions!"
                  );
        caster->remove_property("swarm");
        TO->remove();
        return;
    } else {
        inv = all_inventory(here);
        for (max = 0; max < sizeof(inv); max++) {
            if (living(inv[max]) && inv[max] != caster && !inv[max]->query_true_invis()) {
                if (present(caster, here)) {
                    tell_object(caster, "%^RESET%^%^GREEN%^" +
                                "The swarm stings and bites and buzzes around "
                                + inv[max]->query_cap_name() +
                                "!%^RESET%^"
                                );
                }
                tell_object(inv[max], "%^RESET%^%^GREEN%^" +
                            "The swarm stings and bites and buzzes around you!%^RESET%^"
                            );
                tell_room(here, "%^RESET%^%^GREEN%^" +
                          "The swarm stings and bites and buzzes around "
                          + inv[max]->query_cap_name() +
                          "!%^RESET%^"
                          , ({ caster, inv[max] }));
                if (random(99) + 1 > (int)inv[max]->query_property("magic resistance")) {
                    inv[max]->do_damage(inv[max]->return_target_limb(), 1);
                    if (!userp(inv[max]) && (int)inv[max]->query_hp() < 0 && !present(caster, here)) {
                        inv[max]->remove();
                    }
                }
            }
        }
        cycle = cycle + 1;
        call_out("sting", 8);
        return;
    }
}
