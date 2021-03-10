//forest46.c

#include "../../newbie.h"

inherit FOREST"inherit/forestberries";
//inherit the base room for the main forest w/berries

void create(){
    ::create();
    set_exits(([
        "north":FOREST"forest39",
        "northeast":FOREST"forest40",
        "east":FOREST"forest47",
        "southeast":FOREST"forest54",
        "south":FOREST"forest53",
        "southwest":FOREST"forest52",
        "west":FOREST"forest45",
        "northwest":FOREST"forest38",
    ]));
}
