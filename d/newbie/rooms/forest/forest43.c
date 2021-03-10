//forest43.c

#include "../../newbie.h"

inherit FOREST"inherit/forestpaths";
//inherit the base room for the areas near the paths

void create(){
    ::create();
    set_exits(([
      "north":FOREST"forest36",
      "northeast":FOREST"forest37",
        "east":FOREST"forest44",
        "southeast":FOREST"forest51",
      "northwest":FOREST"forest35",
    ]));
}
