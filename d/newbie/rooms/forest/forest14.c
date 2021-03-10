//forest14.c

#include "../../newbie.h"

inherit FOREST"inherit/forestberries";
//inherit the base room for rooms with berries in the main forest

void create(){
   ::create();
   set_exits(([
       "northwest":FOREST"forest5",
       "north":FOREST"forest6",
       "east":FOREST"forest15",
       "southeast":FOREST"forest23",
       "south":FOREST"forest22",
       "southwest":FOREST"forest21",
       "west":FOREST"forest13",
   ]));
}
