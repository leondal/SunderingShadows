//forest26.c

#include "../../newbie.h"

inherit FOREST"inherit/forestlake";
//inherit the base room with fishing for near the lake

void create(){
   ::create();
   set_exits(([
       "north":FOREST"forest18",
       "northeast":FOREST"forest19",
       "east":FOREST"forest27",
       "southeast":FOREST"forest37",
       "south":FOREST"forest36",
       "southwest":FOREST"forest35",
   ]));
}
