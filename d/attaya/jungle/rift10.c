//Octothorpe (3/29/10)
//Attaya Volcanic Rift Valley 10

#include <std.h>
#include "../defs.h"
inherit RIFT;

void create()
{
   ::create();
   set_exits(([
      "northwest":JGL"rift8",
      "northeast":JGL"rift33",
      "east":JGL"rift12",
      "south":JGL"rift31",
      "west":JGL"rift32",
   ]));
}