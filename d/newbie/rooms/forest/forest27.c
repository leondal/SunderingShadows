//forest27.c

#include "../../newbie.h"

inherit FOREST"inherit/forestpaths";
//inherit the base room for the areas near the paths

void create(){
   ::create();
   set_exits(([
       "north":FOREST"forest19",
       "northeast":FOREST"forest20",
       "east":FOREST"forest28",
       "southeast":FOREST"forest38",
       "south":FOREST"forest37",
       "southwest":FOREST"forest36",
       "west":FOREST"forest26",
       "northwest":FOREST"forest18",
   ]));
}
