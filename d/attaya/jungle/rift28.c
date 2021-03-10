//Octothorpe (5/5/16)
//Attaya Volcanic Rift Valley 28

#include <std.h>
#include "../defs.h"
inherit RIFT;

void create()
{
   ::create();
   set_exits(([
      "north":JGL"rift30",
      "east":JGL"rift29",
      "west":JGL"rift24"
   ]));
}