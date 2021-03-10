#include <std.h>
#include <clock.h>

inherit DISEASE;

int next_step = 0;
int saved = 0;

void create()
{
    ::create();
    set_name("red ache");
    set_incubation("1d3 days");
    set_damage_desc("1d6 str");
    set_infection("inhaled");
    set_description("\n\nSkin turns red and warm to the touch, you have a compulsion to scratch it.");

    set_property("inanimate bonus", 1);
    set_heart_beat(32);
}

int init_disease(int dc)
{
    ::init_disease(dc);
    next_step = ETO->query_age() + DAY * roll_dice(1, 3);
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

    set_item_bonus("strength",dmg);

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

    if (!random(240)) {
        tell_object(ETO,"\n%^BOLD%^%^BLUE%^Your skin aches and begs to be scratched.%^RESET%^");
    }

    return;
}
