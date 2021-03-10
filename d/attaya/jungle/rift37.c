//Octothorpe (5/5/16)
//Attaya Volcanic Rift Valley 37

#include <std.h>
#include "../defs.h"
inherit RIFT;

void create()
{
   ::create();
   set_exits(([
      "north":JGL"rift26",
      "south":JGL"rift40",
      "west":JGL"rift36"
   ]));
}