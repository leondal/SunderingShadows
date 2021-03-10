#include <std.h>
#include <daemons.h>
inherit OBJECT;

object caster;
int level, cycle, total;

void setup_swarm(object obcaster, int oblevel);
void done();

void init()
{
    ::init();
    add_action("disperse_fun", "disperse");
}

void create()
{
    ::create();
    set_name("ectoplasmic swarm");
    set_id(({ "swarm", "ectoplasmic swarm", "ectoplasmic_swarm" }));
    set_short("a swarm of tiny crystals");
    set_long(
        "This is a swarm of miniscule crystals, though they seem " +
        "to be somewhat insubstantial.  They fly through the air, " +
        "slicing whatever is in their path with their razorsharp " +
        "edges.  It appears almost impossible to fight them!"
        );
    set_weight(100000);
    set_value(0);
    set_property("no animate", 1);
    set_property("magic", 1);
    call_out("slice", 2);
}

int disperse_fun(string str)
{
    if (!str) {
        tell_object(TP, "Disperse what?");
        return 0;
    }
    if (str != "swarm" && str != "ectoplasmic swarm") {
        tell_object(TP, "Disperse what?");
        return 0;
    }
    if (TP != caster) {
        return 0;
    }
    tell_object(TP, "%^BOLD%^%^RED%^With a wave of your hand, the " +
                "swarm disappears.%^RESET%^");
    tell_room(ETO, "%^BOLD%^%^RED%^" + TPQCN + " waves " + TP->QP + " hand, " +
              "and the swarm disappears!", TP);
    caster->remove_property("has_swarm");
    TO->remove();
    return 1;
}

void setup_swarm(object obcaster, int oblevel)
{
    caster = obcaster;
    level = oblevel;
    cycle = 1;
    total = level;
}

void slice()
{
    object here;
    object* inv;
    int max, dmg;
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        return;
    }
    if (!objectp(caster)) {
        done();
        return;
    }
    if (cycle > total) {
        done();
        return;
    } else {
        dmg = level / 2;
        if (dmg > 50) {
            dmg = 50;
        }
        inv = all_inventory(ETO);
        inv = filter_array(inv, "is_non_immortal", FILTERS_D);
        for (max = 0; max < sizeof(inv); max++) {
            if (living(inv[max]) && inv[max] != caster) {
                if (inv[max]->query_true_invis()) {
                    continue;
                }
                if (present(caster, ETO)) {
                    tell_object(caster, "%^BOLD%^%^RED%^" +
                                "The crystals swarm around " +
                                "" + inv[max]->QCN + " " +
                                "and slice " + inv[max]->QO + "!%^RESET%^");
                }
                tell_object(inv[max], "%^BOLD%^%^RED%^" +
                            "The crystals swarm around you, slicing " +
                            "your skin!%^RESET%^");
                tell_room(ETO, "%^BOLD%^%^RED%^" +
                          "The crystals swarm around " + inv[max]->QCN + ", " +
                          "slicing " + inv[max]->QP + " skin" +
                          "!%^RESET%^", ({ caster, inv[max] }));
                if (random(99) + 1 > (int)inv[max]->query_property("magic resistance")) {
                    inv[max]->do_damage(inv[max]->return_target_limb(), dmg);
                    if (!userp(inv[max]) && (int)inv[max]->query_hp() < 0 && !present(caster, ETO)) {
                        inv[max]->remove();
                    }
                }
            }
        }
        cycle++;
        call_out("slice", 6);
        return;
    }
}

void done()
{
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        return;
    }
    tell_room(ETO, "%^RED%^The swarm suddenly disperses, flying off in " +
              "different directions before disappearing!");
    if (objectp(caster)) {
        caster->remove_property("has_swarm");
    }
    TO->remove();
    return;
}
