//Octothorpe (3/28/10)
//Attaya Volcanic Rift Valley 8

#include <std.h>
#include "../defs.h"
inherit RIFT;

void create()
{
   ::create();
   set_exits(([
      "northwest":JGL"rift7",
      "west":JGL"rift21",
      "east":JGL"rift33",
      "southeast":JGL"rift10",
   ]));
}