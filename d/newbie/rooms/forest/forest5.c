//forest5.c

#include "../../newbie.h"

inherit FOREST"inherit/forestedge";
//inherit the base room for the edge of the forest

void create(){
   ::create();
   set_exits(([
      "west":FOREST"forest4",
      "east":FOREST"forest6",
      "southwest":FOREST"forest12",
      "south":FOREST"forest13",
      "southeast":FOREST"forest14",
   ]));
}
