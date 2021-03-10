//forest53.c

#include "../../newbie.h"

inherit FOREST"inherit/forestmain";
//inherit the base room for the main forest

void create(){
    ::create();
    set_exits(([
        "north":FOREST"forest46",
        "northeast":FOREST"forest47",
        "east":FOREST"forest54",
        "southeast":FOREST"forest63",
        "south":FOREST"forest62",
        "southwest":FOREST"forest61",
        "west":FOREST"forest52",
        "northwest":FOREST"forest45",
    ]));
}
