//Octothorpe (5/5/16)
//Attaya Volcanic Rift Valley 25

#include <std.h>
#include "../defs.h"
inherit RIFT;

void create()
{
   ::create();
   set_exits(([
      "east":JGL"rift26",
      "northwest":JGL"rift24",
      "southwest":JGL"rift35"
   ]));
}