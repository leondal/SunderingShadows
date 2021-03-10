//forest1.c

#include "../../newbie.h"

inherit FOREST"inherit/forestedge";
//inherit the base room for the edge of the forest

void create(){
   ::create();
   set_exits(([
      "south":FOREST"forest9",
      "east":FOREST"forest2",
      "southeast":FOREST"forest10",
   ]));
}
