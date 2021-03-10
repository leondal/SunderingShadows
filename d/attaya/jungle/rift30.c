//Octothorpe (5/5/16)
//Attaya Volcanic Rift Valley 30

#include <std.h>
#include "../defs.h"
inherit RIFT;

void create()
{
   ::create();
   set_exits(([
      "north":JGL"rift32",
      "south":JGL"rift28",
      "east":JGL"rift31",
      "west":JGL"rift23"
   ]));
}