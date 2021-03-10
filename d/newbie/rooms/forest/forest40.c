//forest40.c

#include "../../newbie.h"

inherit FOREST"inherit/forestmain";
//inherit the base room for the main forest

void create(){
    ::create();
    set_exits(([
        "north":FOREST"forest30",
        "northeast":FOREST"forest31",
        "east":FOREST"forest41",
        "southeast":FOREST"forest48",
        "south":FOREST"forest47",
        "southwest":FOREST"forest46",
        "west":FOREST"forest39",
        "northwest":FOREST"forest29",
    ]));
}
