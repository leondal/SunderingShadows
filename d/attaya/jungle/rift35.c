//Octothorpe (5/5/16)
//Attaya Volcanic Rift Valley 35

#include <std.h>
#include "../defs.h"
inherit RIFT;

void create()
{
   ::create();
   set_exits(([
      "northeast":JGL"rift25",
      "south":JGL"rift38",
      "east":JGL"rift36",
   ]));
}