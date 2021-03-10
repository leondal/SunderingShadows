//forest41.c

#include "../../newbie.h"

inherit FOREST"inherit/forestpaths";
//inherit the base room for the areas near the paths

void create(){
    ::create();
    set_exits(([
        "north":FOREST"forest31",
        "northeast":FOREST"forest32",
        "east":FOREST"forest42",
        "southeast":FOREST"forest49",
        "south":FOREST"forest48",
        "southwest":FOREST"forest47",
        "west":FOREST"forest40",
        "northwest":FOREST"forest30",
    ]));
}
