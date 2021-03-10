//Octothorpe (5/5/16)
//Attaya Volcanic Rift Valley 34

#include <std.h>
#include "../defs.h"
inherit RIFT;

void create()
{
   ::create();
   set_exits(([
      "south":JGL"rift12",
      "west":JGL"rift33",
   ]));
}