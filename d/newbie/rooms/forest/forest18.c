//forest18.c

#include "../../newbie.h"

inherit FOREST"inherit/forestlake";
//inherit the base room with fishing for near the lake

void create(){
   ::create();
   set_exits(([
       "north":FOREST"forest10",
       "northeast":FOREST"forest11",
       "east":FOREST"forest19",
       "southeast":FOREST"forest27",
       "south":FOREST"forest26",
       "northwest":FOREST"forest9",
   ]));
}
