//forest60.c

#include "../../newbie.h"

inherit FOREST"inherit/forestmain";
//inherit the base room for the main forest

void create(){
    ::create();
    set_exits(([
        "north":FOREST"forest51",
        "northeast":FOREST"forest52",
        "east":FOREST"forest61",
        "southeast":FOREST"forest68",
        "south":FOREST"forest67",
        "west":FOREST"forest59",
    ]));
}
