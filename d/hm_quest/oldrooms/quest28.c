#include <std.h>

inherit "/d/hm_quest/rooms/quest1.c";

void create()
{
    ::create();
    set_long("%^ORANGE%^You have reached the other side of the small island.  Waves, once more "
        "lap at the golden sand and a tropical breeze fills the air.  More evidence of life is "
        "here, small huts seen off in the distance to the east, and small skiffs appear to be "
        "awaiting the owners.  Nets of brightly coloured vines lay upon the sand, waiting to be "
        "tossed and used.");
    set_exits(([
        "north" : "/d/hm_quest/rooms/quest29",
        "south" : "/d/hm_quest/rooms/quest27"
    ]));
}
