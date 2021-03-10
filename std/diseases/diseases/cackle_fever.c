#include <std.h>
#include <clock.h>

inherit DISEASE;

int next_step = 0;
int saved = 0;

void create()
{
    ::create();
    set_name("cacle fever");
    set_incubation("1 day");
    set_damage_desc("1d6 wis");
    set_infection("inhaled");
    set_description("\n\nSymptoms include high fever, disorientation, and frequent bouts of hideous laughter. Also known as the shieks.");

    set_property("inanimate bonus", 1);
    set_heart_beat(32);
}

int init_disease(int dc)
{
    ::init_disease(dc);
    next_step = ETO->query_age() + DAY;
}

advance_disease()
{
    int dmg = -roll_dice(stage, 6);

    next_step += DAY;

    if (do_save())
    {
        saved++;
        if (saved > 2) {
            TO->remove();
            return;
        }
        return;
    }
    saved = 0;

    set_item_bonus("intelligence",dmg);

    tell_object(ETO,"\n%^BOLD%^%^BLUE%^Your burst out in sudden laughter.%^RESET%^");
    tell_room(EETO, "%^ORANGE%^" + ETO->QCN + " bursts out in sudden laughter!%^RESET%^", ETO);

    stage++;

}

void heart_beat()
{
    if (!objectp(TO)) {
        return;
    }

    if (!next_step) {
        return;
    }

    if (!ETO->is_living()) {
        TO->remove();
    }
    if (ETO->query_age() > next_step) {
        advance_disease();
    }

    if (stage > 1) {
        if (!random(120)) {
            tell_object(ETO, "\n%^BOLD%^%^BLUE%^Your burst out in sudden laughter.%^RESET%^");
            tell_room(EETO, "%^ORANGE%^" + ETO->QCN + " bursts out in sudden laughter!%^RESET%^", ETO);
        }
    }

    return;
}
