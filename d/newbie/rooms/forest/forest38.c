//forest38.c

#include "../../newbie.h"

inherit FOREST"inherit/forestmain";
//inherit the base room for the main forest

void create(){
    ::create();
    set_exits(([
        "north":FOREST"forest28",
        "northeast":FOREST"forest29",
        "east":FOREST"forest39",
        "southeast":FOREST"forest46",
        "south":FOREST"forest45",
        "southwest":FOREST"forest44",
        "west":FOREST"forest37",
        "northwest":FOREST"forest27",
    ]));
}
