//Octothorpe (3/29/10)
//Attaya Volcanic Rift Valley 12

#include <std.h>
#include "../defs.h"
inherit RIFT;

void create()
{
   ::create();
   set_exits(([
      "southwest":JGL"rift14",
      "west":JGL"rift10",
      "northwest":JGL"rift33",
      "north":JGL"rift34",
   ]));
}