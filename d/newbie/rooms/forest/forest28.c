//forest28.c

#include "../../newbie.h"

inherit FOREST"inherit/forestmain";
//inherit the base room for the main forest

void create(){
   ::create();
   set_exits(([
       "north":FOREST"forest20",
       "northeast":FOREST"forest21",
       "east":FOREST"forest29",
       "southeast":FOREST"forest39",
       "south":FOREST"forest38",
       "southwest":FOREST"forest37",
       "west":FOREST"forest27",
       "northwest":FOREST"forest19",
   ]));
}
