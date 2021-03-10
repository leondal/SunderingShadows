//forest10.c

#include "../../newbie.h"

inherit FOREST"inherit/forestlake";
//inherit the base room with fishing for near the lake

void create(){
   ::create();
   set_exits(([
       "northwest":FOREST"forest1",
       "north":FOREST"forest2",
       "northeast":FOREST"forest3",
       "east":FOREST"forest11",
       "southeast":FOREST"forest19",
       "south":FOREST"forest18",
       "west":FOREST"forest9",
   ]));
}
