#include <std.h>
#include <clock.h>

inherit DISEASE;

int next_step = 0;
int saved = 0;

void create()
{
    ::create();
    set_name("shakes");
    set_incubation("1 day");
    set_damage_desc("1d8 dex");
    set_infection("contact");
    set_description("\n\nCauses involuntary twitches, tremors, and fits..");

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
    int dmg = -roll_dice(stage, 8);

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

    set_item_bonus("dexterity",dmg);

    tell_object(ETO,"\n%^BOLD%^%^BLUE%^Your shake and twitch.%^RESET%^");
    tell_room(EETO, "%^ORANGE%^" + ETO->QCN + " shakes and twitches.%^RESET%^", ETO);

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
            tell_object(ETO, "\n%^BOLD%^%^BLUE%^Your shake and twitch.%^RESET%^");
            tell_room(EETO, "%^ORANGE%^" + ETO->QCN + " shakes and twitches.%^RESET%^", ETO);
        }
    }

    return;
}
