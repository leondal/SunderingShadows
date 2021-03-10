//forest4.c

#include "../../newbie.h"

inherit FOREST"inherit/forestedge";
//inherit the base room for the edge of the forest

void create(){
   ::create();
   set_exits(([
      "west":FOREST"forest3",
      "east":FOREST"forest5",
      "southwest":FOREST"forest11",
      "south":FOREST"forest12",
      "southeast":FOREST"forest13",
   ]));
}
