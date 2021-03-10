//Octothorpe (5/5/16)
//Attaya Volcanic Rift Valley 27

#include <std.h>
#include "../defs.h"
inherit RIFT;

void create()
{
   ::create();
   set_exits(([
      "north":JGL"rift18",
      "northwest":JGL"rift15",
   ]));
}