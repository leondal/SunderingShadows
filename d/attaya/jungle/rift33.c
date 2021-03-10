//Octothorpe (5/5/16)
//Attaya Volcanic Rift Valley 33

#include <std.h>
#include "../defs.h"
inherit RIFT;

void create()
{
   ::create();
   set_exits(([
      "southwest":JGL"rift10",
      "southeast":JGL"rift12",
      "east":JGL"rift34",
      "west":JGL"rift8"
   ]));
}