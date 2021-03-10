#include <std.h>

inherit "/d/hm_quest/rooms/quest1.c";

void create()
{
    :: create();
    set_indoors(1);
    set_long("%^RED%^The hut is a mess.  Built out of vines, large saplings and leaves, it has "
        "withstood time very well.  However, claw marks are upon the little furniture there is.  "
        "A smashed table, broken chair and a bed which could now be used only for kindling, show "
        "the intruders haste and anger.  Streaks of blood mark the floor and bedding.  A severed "
        "finger, partially chewed rests upon a shelf, as if waiting, as a midnight snack.");
    set_exits(([
        "out" : "/d/hm_quest/rooms/quest26",
        "door" : "/d/hm_quest/rooms/quest24"
    ]));
}
