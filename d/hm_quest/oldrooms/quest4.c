#include <std.h>

inherit "/d/hm_quest/rooms/quest1.c";

void create()
{
    :: create();
    set_long("%^ORANGE%^The stands of poplar begin to thicken and grow taller as the path shrinks "
        "to only two feet wide.  Great boughs form bowers of green overhead, making it difficult "
        "to make out the time of day.  You can make out slanted green eyes peering from behind rocks "
        "and trees.  You realize you may not be the alone upon this island, but rather, intruding upon "
        "the domain of the inhabitants.");
    set_exits(([
        "north" : "/d/hm_quest/rooms/quest2",
        "east" : "/d/hm_quest/rooms/quest3",
        "southwest" : "/d/hm_quest/rooms/quest5"
    ]));
}
