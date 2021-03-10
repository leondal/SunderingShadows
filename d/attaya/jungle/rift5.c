//Octothorpe (3/28/10)
//Attaya Volcanic Rift Valley 5

#include <std.h>
#include "../defs.h"
inherit RIFT;

void create()
{
   ::create();
   set_exits(([
      "north":JGL"rift4",
      "west":JGL"rift3",
      "east":JGL"rift23",
      "southeast":JGL"rift24",
   ]));
}