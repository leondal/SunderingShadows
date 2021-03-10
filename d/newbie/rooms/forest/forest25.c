//forest25

#include "../../newbie.h"

inherit FOREST"inherit/forestedge";
//inherit the base room for the areas near the paths

void create(){
   ::create();
   set_exits(([
       "southeast":FOREST"forest34",
       "south":FOREST"forest33",
       "southwest":FOREST"forest32",
       "west":FOREST"forest24",
   ]));
}
