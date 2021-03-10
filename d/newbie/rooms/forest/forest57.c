//forest57.c

#include "../../newbie.h"

inherit FOREST"inherit/forestmain";
//inherit the base room for the main forest

void create(){
    ::create();
    set_exits(([
        "north":FOREST"forest50",
        "east":FOREST"forest58",
        "south":FOREST"forest66",
        "southwest":FOREST"forest65",
        "west":FOREST"forest56",
        "northwest":FOREST"forest49",
    ]));
}
