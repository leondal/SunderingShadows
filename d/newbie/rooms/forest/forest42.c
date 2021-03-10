//forest42.c

#include "../../newbie.h"

inherit FOREST"inherit/forestpaths";
//inherit the base room for the areas near the paths

void create(){
    ::create();
    set_exits(([
        "north":FOREST"forest32",
        "northeast":FOREST"forest33",
        "southeast":FOREST"forest50",
        "south":FOREST"forest49",
        "southwest":FOREST"forest48",
        "west":FOREST"forest41",
        "northwest":FOREST"forest31",
    ]));
}
