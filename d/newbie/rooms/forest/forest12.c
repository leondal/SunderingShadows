//forest12.c

#include "../../newbie.h"

inherit FOREST"inherit/forestmain";
//inherit the base room for the main forest

void create(){
   ::create();
   set_exits(([
       "northwest":FOREST"forest3",
       "north":FOREST"forest4",
       "northeast":FOREST"forest5",
       "east":FOREST"forest13",
       "southeast":FOREST"forest21",
       "south":FOREST"forest20",
       "southwest":FOREST"forest19",
       "west":FOREST"forest11",
   ]));
}
