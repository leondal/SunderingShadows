//Octothorpe (5/5/16)
//Attaya Volcanic Rift Valley 42

#include <std.h>
#include "../defs.h"
inherit RIFT;

void create()
{
   ::create();
   set_exits(([
      "north":JGL"rift39",
      "east":JGL"rift43",
      "west":JGL"rift41"
   ]));
}