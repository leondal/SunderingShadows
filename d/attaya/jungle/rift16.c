//Octothorpe (3/29/10)
//Attaya Volcanic Rift Valley 16

#include <std.h>
#include "../defs.h"
inherit RIFT;

void create()
{
   ::create();
   set_exits(([
	  "west":JGL"rift14",
	  "south":JGL"rift18"
   ]));
}