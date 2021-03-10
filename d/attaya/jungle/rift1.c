//Octothorpe (3/28/10)
//Attaya Volcanic Rift Valley 1

#include <std.h>
#include "../defs.h"
inherit RIFT;

void create()
{
   ::create();
   set_exits(([
      "southwest":JGL"jun33",
      "south":JGL"rift2",
      "east":JGL"rift6",
      "southeast":JGL"rift4"
   ]));
}