//forest39.c

#include "../../newbie.h"

inherit FOREST"inherit/forestmain";
//inherit the base room for the main forest

void create(){
    ::create();
    set_exits(([
        "north":FOREST"forest29",
        "northeast":FOREST"forest30",
        "east":FOREST"forest40",
        "southeast":FOREST"forest47",
        "south":FOREST"forest46",
        "southwest":FOREST"forest45",
        "west":FOREST"forest38",
        "northwest":FOREST"forest28",
    ]));
}
