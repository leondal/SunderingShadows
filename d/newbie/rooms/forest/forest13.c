//forest13.c

#include "../../newbie.h"

inherit FOREST"inherit/forestmain";
//inherit the base room for the main forest

void create(){
   ::create();
   set_exits(([
       "northwest":FOREST"forest4",
       "north":FOREST"forest5",
       "northeast":FOREST"forest6",
       "east":FOREST"forest14",
       "southeast":FOREST"forest22",
       "south":FOREST"forest21",
       "southwest":FOREST"forest20",
       "west":FOREST"forest12",
   ]));
}
