//Octothorpe (5/5/16)
//Attaya Volcanic Rift Valley 31

#include <std.h>
#include "../defs.h"
inherit RIFT;

void create()
{
   ::create();
   set_exits(([
      "north":JGL"rift10",
      "south":JGL"rift29",
      "east":JGL"rift14",
      "west":JGL"rift30"
   ]));
}