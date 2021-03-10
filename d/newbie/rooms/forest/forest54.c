//forest43.c

#include "../../newbie.h"

inherit FOREST"inherit/forestmain";
//inherit the base room for the main forest

void create(){
    ::create();
    set_exits(([
        "north":FOREST"forest47",
        "northeast":FOREST"forest48",
        "east":FOREST"forest55",
        "southeast":FOREST"forest64",
        "south":FOREST"forest63",
        "southwest":FOREST"forest62",
        "west":FOREST"forest53",
        "northwest":FOREST"forest46",
    ]));
}
