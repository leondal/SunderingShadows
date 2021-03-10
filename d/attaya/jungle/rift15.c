//Octothorpe (5/5/16)
//Attaya Volcanic Rift Valley 15

#include <std.h>
#include "../defs.h"
inherit RIFT;

void create()
{
   ::create();
   set_exits(([
      "northeast":JGL"rift18",
      "southeast":JGL"rift27",
      "west":JGL"rift26"
   ]));
}