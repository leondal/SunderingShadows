//forest3.c

#include "../../newbie.h"

inherit FOREST"inherit/forestedge";
//inherit the base room for the edge of the forest

void create(){
   ::create();
   set_exits(([
      "west":FOREST"forest2",
      "east":FOREST"forest4",
      "southwest":FOREST"forest10",
      "south":FOREST"forest11",
      "southeast":FOREST"forest12",
   ]));
}
