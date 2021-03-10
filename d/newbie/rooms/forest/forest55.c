//forest55.c

#include "../../newbie.h"

inherit FOREST"inherit/forestmain";
//inherit the base room for the main forest

void create(){
    ::create();
    set_exits(([
        "north":FOREST"forest48",
        "northeast":FOREST"forest49",
        "east":FOREST"forest56",
        "southeast":FOREST"forest65",
        "south":FOREST"forest64",
        "southwest":FOREST"forest63",
        "west":FOREST"forest54",
        "northwest":FOREST"forest47",
    ]));
}
