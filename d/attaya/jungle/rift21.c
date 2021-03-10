//Octothorpe (5/5/16)
//Attaya Volcanic Rift Valley 21

#include <std.h>
#include "../defs.h"
inherit RIFT;

void create()
{
   ::create();
   set_exits(([
      "east":JGL"rift8",
      "west":JGL"rift6",
      "south":JGL"rift22"
   ]));
}