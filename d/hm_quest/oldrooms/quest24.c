#include <std.h>

inherit "/d/hm_quest/rooms/quest1.c";

void create()
{
    ::create();
    set_long("%^ORANGE%^A small hut blocks your way.  It is small and round, yet blocks "
        "the path as the thorn bushes around it will not allow passage any other way.");

    set_exits(([
        "hut" : "/d/hm_quest/rooms/quest25",
        "southeast" : "/d/hm_quest/rooms/quest23"
    ]));
}
