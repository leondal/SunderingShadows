//Octothorpe (5/5/16)
//Attaya Volcanic Rift Valley 23

#include <std.h>
#include "../defs.h"
inherit RIFT;

void create()
{
   ::create();
   set_exits(([
      "north":JGL"rift22",
      "east":JGL"rift30",
      "west":JGL"rift5",
      "south":JGL"rift24"
   ]));
}