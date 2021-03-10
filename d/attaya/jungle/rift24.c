//Octothorpe (5/5/16)
//Attaya Volcanic Rift Valley 24

#include <std.h>
#include "../defs.h"
inherit RIFT;

void create()
{
   ::create();
   set_exits(([
      "north":JGL"rift23",
      "east":JGL"rift28",
      "northwest":JGL"rift5",
      "southeast":JGL"rift25"
   ]));
}