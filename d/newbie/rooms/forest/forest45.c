//forest45

#include "../../newbie.h"

inherit FOREST"inherit/forestmain";
//inherit the base room for the main forest

void create(){
    ::create();
    set_exits(([
      "north":FOREST"forest38",
      "northeast":FOREST"forest39",
        "east":FOREST"forest46",
        "southeast":FOREST"forest53",
        "south":FOREST"forest52",
        "southwest":FOREST"forest51",
        "west":FOREST"forest44",
      "northwest":FOREST"forest37",
    ]));
}
