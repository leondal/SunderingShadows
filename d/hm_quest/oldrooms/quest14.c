#include <std.h>

inherit "/d/hm_quest/rooms/quest1.c";

void create()
{
    :: create();
    set_short("%^ORANGE%^A pathway");
    set_long("%^ORANGE%^You have stepped out from the low bushes to the shore once "
        "again.  Bright silicate sand covers north and sough shores, being washed by "
        "gentle waves lapping to and fro.  Brightly coloured fish swim by just beyond "
        "your reach creating a kaleidiscope of colour.  Larger fish can be seen jumping "
        "over waves in the distance.  A couple of rowboats are placed just above the "
        "breakwater, intact with oars and supplies.");
    set_exits(([
        "north" : "/d/hm_quest/rooms/quest13",
        "south" : "/d/hm_quest/rooms/quest15"
    ]));
}
