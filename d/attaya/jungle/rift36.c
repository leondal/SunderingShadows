//Octothorpe (5/5/16)
//Attaya Volcanic Rift Valley 36

#include <std.h>
#include "../defs.h"
inherit RIFT;

void create()
{
   ::create();
   set_exits(([
      "south":JGL"rift39",
      "east":JGL"rift37",
      "west":JGL"rift35"
   ]));
}