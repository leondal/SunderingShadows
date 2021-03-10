//forest37.c

#include "../../newbie.h"

inherit FOREST"inherit/forestpaths";
//inherit the base room for the areas near the paths

void create(){
    ::create();
    set_exits(([
        "north":FOREST"forest27",
        "northeast":FOREST"forest28",
        "east":FOREST"forest38",
        "southeast":FOREST"forest45",
        "south":FOREST"forest44",
        "southwest":FOREST"forest43",
        "west":FOREST"forest36",
        "northwest":FOREST"forest26",
    ]));
}
