//Octothorpe (3/29/10)
//Attaya Volcanic Rift Valley 18

#include <std.h>
#include "../defs.h"
inherit RIFT;

void create()
{
   ::create();
   set_exits(([
      "northwest":JGL"rift14",
	  "east":JGL"rift20",
	  "north":JGL"rift16",
	  "southwest":JGL"rift15",
	  "south":JGL"rift27"
   ]));
}