//Octothorpe (5/5/16)
//Attaya Volcanic Rift Valley 29

#include <std.h>
#include "../defs.h"
inherit RIFT;

void create()
{
   ::create();
   set_exits(([
      "north":JGL"rift31",
      "south":JGL"rift26",
      "east":JGL"rift18",
      "west":JGL"rift28"
   ]));
}