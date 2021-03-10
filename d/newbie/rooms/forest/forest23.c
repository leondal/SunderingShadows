//forest23.c

#include "../../newbie.h"

inherit FOREST"inherit/forestedge";
//inherit the base room for the main forest

void create(){
   ::create();
   set_exits(([
       "north":FOREST"forest15",
       "east":FOREST"forest24",
       "southeast":FOREST"forest32",
       "south":FOREST"forest31",
       "southwest":FOREST"forest30",
       "west":FOREST"forest22",
       "northwest":FOREST"forest14",
   ]));
}
