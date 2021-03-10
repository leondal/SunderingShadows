//Octothorpe (3/28/10)
//Attaya Volcanic Rift Valley 6

#include <std.h>
#include "../defs.h"
inherit RIFT;

void create()
{
   ::create();
   set_exits(([
      "northeast":JGL"rift7",
      "west":JGL"rift1",
      "east":JGL"rift21",
      "south":JGL"rift4"	  
   ]));
}