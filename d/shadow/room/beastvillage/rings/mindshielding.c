#include <std.h>
inherit "/d/shadow/room/beastvillage/rings/base_inherit";

int mytracker;

void create()
{
    ::create();
    add_id("ring of mind shielding");
    add_id("Ring of Mind Shielding");
    set_short("%^RESET%^%^ORANGE%^Ring of Mi%^GREEN%^n%^ORANGE%^d Shie%^YELLOW%^l%^RESET%^%^ORANGE%^ding%^RESET%^");
    set_wear((: TO, "wear_fun" :));
    set_remove((: TO, "remove_fun" :));
    set_item_bonus("will", 4);
    set_mylong("bull");
    set_mylore("bull, whose stubborn tenacity allow it to push past even the most gruelling of impediments");
}

int wear_fun()
{
    if (owned && (string)ETO->query_name() != owner && !avatarp(ETO)) {
        tell_object(ETO, "The ring doesn't seem to fit you.");
        return 0;
    }
    if (ETO->query_level() < 15) { // tier 2 ring
        tell_object(ETO, "The ring doesn't seem to fit you.");
        return 0;
    }
    return 1;
}

int remove_fun()
{
    return 1;
}
