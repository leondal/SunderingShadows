//forest29.c

#include "../../newbie.h"

inherit FOREST"inherit/forestmain";
//inherit the base room for the main forest

void create(){
   ::create();
   set_exits(([
       "north":FOREST"forest21",
       "northeast":FOREST"forest22",
       "east":FOREST"forest30",
       "southeast":FOREST"forest40",
       "south":FOREST"forest39",
       "southwest":FOREST"forest38",
       "west":FOREST"forest28",
       "northwest":FOREST"forest20",
   ]));
}
