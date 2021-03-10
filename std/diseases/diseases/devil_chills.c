#include <std.h>
#include <clock.h>

inherit DISEASE;

int next_step = 0;
int saved = 0;

void create()
{
    ::create();
    set_name("devil chills");
    set_incubation("1d4 days");
    set_damage_desc("1d4 str");
    set_infection("injury");
    set_description("\n\nBarbazu and pit fiends spread it. It takes three, not two, successful saves in a row to recover from devil chills.");

    set_property("inanimate bonus", 1);
    set_heart_beat(32);
}

int init_disease(int dc)
{
    ::init_disease(dc);
    next_step = ETO->query_age() + DAY * roll_dice(1, 4);
}

advance_disease()
{
    int dmg = -roll_dice(stage, 4);

    next_step += DAY;

    if (do_save())
    {
        saved++;
        if (saved > 3) {
            TO->remove();
            return;
        }
        return;
    }
    saved = 0;

    set_item_bonus("strength",dmg);

    tell_object(ETO,"\n%^BOLD%^%^GREEN%^Your feel very chilly.%^RESET%^");

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
    return;
}
