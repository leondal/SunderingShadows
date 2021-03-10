#include <std.h>
#include <clock.h>

inherit DISEASE;

int next_step = 0;
int saved = 0;

void create()
{
    ::create();
    set_name("demon fever");
    set_incubation("1 day");
    set_damage_desc("1d6 con");
    set_infection("injury");
    set_description("\n\nNight hags spread it.");

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

    set_item_bonus("constitution",dmg);

    tell_object(ETO,"\n%^BOLD%^%^GREEN%^Your fever intensifies.%^RESET%^");

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

    if (stage > 2) {
        if (!random(120)) {
            tell_object(ETO, "\n%^BOLD%^%^BLUE%^You feel significantly under the weather.%^RESET%^");
        }
    }

    return;
}
