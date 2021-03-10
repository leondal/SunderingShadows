//forest36.c

#include "../../newbie.h"

inherit FOREST"inherit/forestlake";
//inherit the base room with fishing for near the lake

void create(){
    ::create();
    set_exits(([
        "north":FOREST"forest26",
        "northeast":FOREST"forest27",
        "east":FOREST"forest37",
        "southeast":FOREST"forest44",
        "south":FOREST"forest43",
        "west":FOREST"forest35",
    ]));
}
