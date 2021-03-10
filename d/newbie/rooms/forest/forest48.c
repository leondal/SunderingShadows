//forest48.c

#include "../../newbie.h"

inherit FOREST"inherit/forestmain";
//inherit the base room for the main forest

void create(){
    ::create();
    set_exits(([
      "north":FOREST"forest41",
      "northeast":FOREST"forest42",
        "east":FOREST"forest49",
        "southeast":FOREST"forest56",
        "south":FOREST"forest55",
        "southwest":FOREST"forest54",
        "west":FOREST"forest47",
      "northwest":FOREST"forest40",
    ]));
}
