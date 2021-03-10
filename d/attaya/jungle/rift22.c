//Octothorpe (5/5/16)
//Attaya Volcanic Rift Valley 22

#include <std.h>
#include "../defs.h"
inherit RIFT;

void create()
{
   ::create();
   set_exits(([
      "north":JGL"rift21",
      "east":JGL"rift32",
      "west":JGL"rift4",
      "south":JGL"rift23"
   ]));
}