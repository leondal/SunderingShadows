//forest44.c

#include "../../newbie.h"

inherit FOREST"inherit/forestmain";
//inherit the base room for the main forest

void create(){
    ::create();
    set_exits(([
      "north":FOREST"forest37",
      "northeast":FOREST"forest38",
        "east":FOREST"forest45",
        "southeast":FOREST"forest52",
        "south":FOREST"forest51",
        "west":FOREST"forest43",
      "northwest":FOREST"forest36",
    ]));
}
