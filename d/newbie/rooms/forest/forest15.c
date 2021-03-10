//forest15.c

#include "../../newbie.h"

inherit FOREST"inherit/forestedge";
//inherit the base room for the main forest

void create(){
   ::create();
   set_exits(([
       "northwest":FOREST"forest6",
       "southeast":FOREST"forest24",
       "south":FOREST"forest23",
       "southwest":FOREST"forest22",
       "west":FOREST"forest14",
   ]));
}
