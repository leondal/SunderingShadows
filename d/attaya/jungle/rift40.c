//Octothorpe (5/5/16)
//Attaya Volcanic Rift Valley 40

#include <std.h>
#include "../defs.h"
inherit RIFT;

void create()
{
   ::create();
   set_exits(([
      "north":JGL"rift37",
      "south":JGL"rift43",
      "west":JGL"rift39"
   ]));
}