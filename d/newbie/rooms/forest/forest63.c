//forest43.c

#include "../../newbie.h"

inherit FOREST"inherit/forestmain";
//inherit the base room for the main forest

void create(){
    ::create();
    set_exits(([
        "north":FOREST"forest54",
        "northeast":FOREST"forest55",
        "east":FOREST"forest64",
        "southeast":FOREST"forest71",
        "south":FOREST"forest70",
        "southwest":FOREST"forest69",
        "west":FOREST"forest62",
        "northwest":FOREST"forest53",
    ]));
}
