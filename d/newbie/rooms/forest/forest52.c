//forest52.c

#include "../../newbie.h"

inherit FOREST"inherit/forestmain";
//inherit the base room for the main forest

void create(){
    ::create();
    set_exits(([
        "north":FOREST"forest45",
        "northeast":FOREST"forest46",
        "east":FOREST"forest53",
        "southeast":FOREST"forest62",
        "south":FOREST"forest61",
        "southwest":FOREST"forest60",
        "west":FOREST"forest51",
        "northwest":FOREST"forest44",
    ]));
}
