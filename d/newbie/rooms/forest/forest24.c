//forest24.c

#include "../../newbie.h"

inherit FOREST"inherit/forestedge";
//inherit the base room for the main forest

void create(){
   ::create();
   set_exits(([
       "northwest":FOREST"forest15",
       "east":FOREST"forest25",
       "southeast":FOREST"forest33",
       "south":FOREST"forest32",
       "southwest":FOREST"forest31",
       "west":FOREST"forest23",
   ]));
}
