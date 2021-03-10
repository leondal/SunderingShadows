//forest19.c

#include "../../newbie.h"

inherit FOREST"inherit/forestberries";
//inherit the base room for the main forest

void create(){
   ::create();
   set_exits(([
       "north":FOREST"forest11",
       "northeast":FOREST"forest12",
       "east":FOREST"forest20",
       "southeast":FOREST"forest28",
       "south":FOREST"forest27",
       "southwest":FOREST"forest26",
       "west":FOREST"forest18",
       "northwest":FOREST"forest10",
   ]));
}
