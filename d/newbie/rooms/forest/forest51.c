//forest43.c

#include "../../newbie.h"

inherit FOREST"inherit/forestedge";
//inherit the base room for the edge of the forest

void create(){
    ::create();
    set_exits(([
        "north":FOREST"forest44",
        "northeast":FOREST"forest45",
        "east":FOREST"forest52",
        "southeast":FOREST"forest61",
        "south":FOREST"forest60",
        "southwest":FOREST"forest59",
        "northwest":FOREST"forest43",
    ]));
}
