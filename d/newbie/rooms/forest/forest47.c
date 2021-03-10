//forest47.c

#include "../../newbie.h"

inherit FOREST"inherit/forestmain";
//inherit the base room for the main forest

void create(){
    ::create();
    set_exits(([
      "north":FOREST"forest40",
      "northeast":FOREST"forest41",
        "east":FOREST"forest48",
        "southeast":FOREST"forest55",
        "south":FOREST"forest54",
        "southwest":FOREST"forest53",
        "west":FOREST"forest46",
      "northwest":FOREST"forest39",
    ]));
}
