//forest11.c

#include "../../newbie.h"

inherit FOREST"inherit/forestmain";
//inherit the base room for the main forest

void create(){
   ::create();
   set_exits(([
       "northwest":FOREST"forest2",
       "north":FOREST"forest3",
       "northeast":FOREST"forest4",
       "east":FOREST"forest12",
       "southeast":FOREST"forest20",
       "south":FOREST"forest19",
       "southwest":FOREST"forest18",
       "west":FOREST"forest10",
   ]));
}
