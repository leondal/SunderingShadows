//forest62.c

#include "../../newbie.h"

inherit FOREST"inherit/forestmain";
//inherit the base room for the main forest

void create(){
    ::create();
    set_exits(([
        "north":FOREST"forest53",
        "northeast":FOREST"forest54",
        "east":FOREST"forest63",
        "southeast":FOREST"forest70",
        "south":FOREST"forest69",
        "southwest":FOREST"forest68",
        "west":FOREST"forest61",
        "northwest":FOREST"forest52",
    ]));
}
