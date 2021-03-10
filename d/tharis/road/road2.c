//d/tharis/road/road2.c//
#include <std.h>
#include <objects.h>

inherit "/d/tharis/road/road1.c";

void create()
{
    ::create();
    set_terrain(HILLS);
    set_travel(DIRT_ROAD);
    set_light(2);
    set_indoors(0);
    set_exits(([
                   "south" : "/d/tharis/road/road3",
                   "north" : "/d/tharis/road/road1"
                   ]));
}
