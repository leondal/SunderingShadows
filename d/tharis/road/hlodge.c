#include <std.h>
#include "../eroad.h"
inherit ROOM;

void create()
{
    ::create();
    set_travel(DIRT_ROAD);
    set_terrain(LIGHT_FOREST);

    set_short("%^ORANGE%^Hunter's lodge");
    set_long(query_short() + "\n");

}
