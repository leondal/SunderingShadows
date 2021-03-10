//Octothorpe (3/29/10)
//Attaya Volcanic Rift Valley 14

#include <std.h>
#include "../defs.h"
inherit RIFT;

void create()
{
   ::create();
   set_exits(([
      "northeast":JGL"rift12",
      "east":JGL"rift16",
      "west":JGL"rift31",
      "southeast":JGL"rift18"
   ]));
}