//forest56.c

#include "../../newbie.h"

inherit FOREST"inherit/forestberries";
//inherit the base room for the main forest w/berries

void create(){
    ::create();
    set_exits(([
        "north":FOREST"forest49",
        "northeast":FOREST"forest50",
        "east":FOREST"forest57",
        "southeast":FOREST"forest66",
        "south":FOREST"forest65",
        "southwest":FOREST"forest64",
        "west":FOREST"forest55",
        "northwest":FOREST"forest48",
    ]));
}
