//Octothorpe (4/11/10)
//Attaya Volcanic Rift Valley 11

#include <std.h>
#include "../defs.h"
inherit RIFT;

void create()
{
   ::create();
   set_exits(([
	  "northeast":JGL"rift13",
	  "south":JGL"rift9"
   ]));
}