//Octothorpe (3/28/10)
//Attaya Volcanic Rift Valley 2

#include <std.h>
#include "../defs.h"
inherit RIFT;

void create()
{
   ::create();
   set_exits(([
      "north":JGL"rift1",
      "west":JGL"jun33",
      "south":JGL"rift3"
   ]));
}