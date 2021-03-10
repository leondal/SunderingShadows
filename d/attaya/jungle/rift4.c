//Octothorpe (3/28/10)
//Attaya Volcanic Rift Valley 4

#include <std.h>
#include "../defs.h"
inherit RIFT;

void create()
{
   ::create();
   set_exits(([
      "north":JGL"rift6",
      "northwest":JGL"rift1",
      "east":JGL"rift22",
      "south":JGL"rift5"
   ]));
}