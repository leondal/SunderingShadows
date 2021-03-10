//Octothorpe (3/28/10)
//Attaya Volcanic Rift Valley 3

#include <std.h>
#include "../defs.h"
inherit RIFT;

void create()
{
   ::create();
   set_exits(([
      "northwest":JGL"jun33",
      "north":JGL"rift2",
      "east":JGL"rift5"	  
   ]));
}