//Octothorpe (5/5/16)
//Attaya Volcanic Rift Valley 38

#include <std.h>
#include "../defs.h"
inherit RIFT;

void create()
{
   ::create();
   set_exits(([
      "north":JGL"rift35",
      "southeast":JGL"rift41",
      "east":JGL"rift39",
   ]));
}