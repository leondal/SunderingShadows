//Octothorpe (3/29/10)
//Attaya Volcanic Rift Valley 20

#include <std.h>
#include "../defs.h"
inherit RIFT;

void create()
{
   ::create();
   set_exits(([
	  "west":JGL"rift18",
      "east":"/d/attaya/firedock",
   ]));
}