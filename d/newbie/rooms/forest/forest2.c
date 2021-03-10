//forest2.c

#include "../../newbie.h"

inherit FOREST"inherit/forestedge";
//inherit the base room for the edge of the forest

void create(){
   ::create();
   set_exits(([
      "west":FOREST"forest1",
      "east":FOREST"forest3",
      "southwest":FOREST"forest9",
      "south":FOREST"forest10",
      "southeast":FOREST"forest11",
   ]));
}
