//forest33.c

#include "../../newbie.h"

inherit FOREST"inherit/forestpaths";
//inherit the base room for the areas near the paths

void create(){
   ::create();
   set_exits(([
       "north":FOREST"forest25",
       "east":FOREST"forest34",
       "southwest":FOREST"forest42",
       "west":FOREST"forest32",
       "northwest":FOREST"forest24",
   ]));
}
