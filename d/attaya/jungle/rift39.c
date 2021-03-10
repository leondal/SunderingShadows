//Octothorpe (5/5/16)
//Attaya Volcanic Rift Valley 39

#include <std.h>
#include "../defs.h"
inherit RIFT;

void create()
{
   ::create();
   set_exits(([
      "north":JGL"rift36",
      "south":JGL"rift42",
      "east":JGL"rift40",
      "west":JGL"rift38"
   ]));
}