#include <std.h>
#include <clock.h>

inherit DISEASE;

int next_step = 0;
int saved = 0;

void create()
{
    ::create();
    set_name("blinding sickness");
    set_incubation("1d3 days");
    set_damage_desc("1d4 str");
    set_infection("injested");
    set_description("\n\nSpread in tainted water. Each time the victim takes 2 or more damage from the disease, he must make another Fortitude save or be permanently blinded.");
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
    int dmg = -roll_dice(stage, 4);

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

    if (dmg < -2) {
        if (!do_save())
        {
            tell_object(ETO,"%^BOLD%^%^BLACK%^You blink in disbelief as your sight disappears.");
            ETO->set_blind(1);
        }
    }

    set_item_bonus("strength",dmg);

    tell_object(ETO,"\n%^BOLD%^%^BLUE%^Your feel fever taking over you.%^RESET%^");

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
    if (!random(180)) {
        if (stage > 1) {
            tell_object(ETO, "\n%^BOLD%^%^BLUE%^Your feel fever taking over you.%^RESET%^");
        }
    }

    return;
}
