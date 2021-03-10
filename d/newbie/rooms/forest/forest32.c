//forest32.c

#include "../../newbie.h"

inherit FOREST"inherit/forestpaths";
//inherit the base room for the areas near the paths

void create(){
   ::create();
   set_exits(([
       "north":FOREST"forest24",
       "northeast":FOREST"forest25",
       "east":FOREST"forest33",
       "south":FOREST"forest42",
       "southwest":FOREST"forest41",
       "west":FOREST"forest31",
       "northwest":FOREST"forest23",
   ]));
}
