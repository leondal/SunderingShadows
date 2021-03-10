//Octothorpe (5/5/16)
//Attaya Volcanic Rift Valley 26

#include <std.h>
#include "../defs.h"
inherit RIFT;

void create()
{
   ::create();
   set_exits(([
      "north":JGL"rift29",
      "south":JGL"rift37",
      "east":JGL"rift15",
      "west":JGL"rift25"
   ]));
}