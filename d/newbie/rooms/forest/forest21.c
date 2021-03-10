//forest21.c

#include "../../newbie.h"

inherit FOREST"inherit/forestmain";
//inherit the base room for the main forest

void create(){
   ::create();
   set_exits(([
       "north":FOREST"forest13",
       "northeast":FOREST"forest14",
       "east":FOREST"forest22",
       "southeast":FOREST"forest30",
       "south":FOREST"forest29",
       "southwest":FOREST"forest28",
       "west":FOREST"forest20",
       "northwest":FOREST"forest12",
   ]));
}
