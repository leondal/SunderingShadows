//Octothorpe (4/11/10)
//Attaya Volcanic Rift Valley 9

#include <std.h>
#include "../defs.h"
inherit RIFT;

void create()
{
   ::create();
   set_exits(([
	  "southwest":JGL"rift7",
	  "north":JGL"rift11"
   ]));
}