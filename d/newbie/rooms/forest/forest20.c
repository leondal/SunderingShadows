//forest20.c

#include "../../newbie.h"

inherit FOREST"inherit/forestmain";
//inherit the base room for the main forest

void create(){
   ::create();
   set_exits(([
       "north":FOREST"forest12",
       "northeast":FOREST"forest13",
       "east":FOREST"forest21",
       "southeast":FOREST"forest29",
       "south":FOREST"forest28",
       "southwest":FOREST"forest27",
       "west":FOREST"forest19",
       "northwest":FOREST"forest11",
   ]));
}
