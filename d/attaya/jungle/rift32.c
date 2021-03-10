//Octothorpe (5/5/16)
//Attaya Volcanic Rift Valley 32

#include <std.h>
#include "../defs.h"
inherit RIFT;

void create()
{
   ::create();
   set_exits(([
      "north":JGL"rift8",
      "south":JGL"rift30",
      "east":JGL"rift10",
      "west":JGL"rift23"
   ]));
}