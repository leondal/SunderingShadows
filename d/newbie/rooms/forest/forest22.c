//forest22.c

#include "../../newbie.h"

inherit FOREST"inherit/forestmain";
//inherit the base room for the main forest

void create(){
   ::create();
   set_exits(([
       "north":FOREST"forest14",
       "northeast":FOREST"forest15",
       "east":FOREST"forest23",
       "southeast":FOREST"forest31",
       "south":FOREST"forest30",
       "southwest":FOREST"forest29",
       "west":FOREST"forest21",
       "northwest":FOREST"forest13",
   ]));
}
