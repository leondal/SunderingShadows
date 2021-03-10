//totally stolen from antioch and crayoned
#include <std.h>
inherit "/std/food.c";

void create()
{
        ::create();
        set_name("%^GREEN%^fresh salad%^RESET%^");
        set_short("%^RESET%^%^GREEN%^fresh salad%^RESET%^");
        set_id(({"salad","food","fresh salad"}));
        set_long(
        "%^GREEN%^This is a fresh salad.  It is full of leafy greens and veggies. "+
        " A slightly sweet dressing has been added to flavor it.%^RESET%^");
        set_weight(1);
        set_value(20);
        set_destroy();
        set_poison(0);
        set_strength(50);
        set_my_mess("You crunch away at the fresh salad.");
        set_your_mess("munches away at the salad.");
}
