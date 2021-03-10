//forest49.c

#include "../../newbie.h"

inherit FOREST"inherit/forestmain";
//inherit the base room for the main forest

void create(){
    ::create();
    set_exits(([
      "north":FOREST"forest42",
        "east":FOREST"forest50",
        "southeast":FOREST"forest57",
        "south":FOREST"forest56",
        "southwest":FOREST"forest55",
        "west":FOREST"forest48",
      "northwest":FOREST"forest41",
    ]));
}
