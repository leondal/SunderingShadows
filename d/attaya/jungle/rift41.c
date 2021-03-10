//Octothorpe (5/5/16)
//Attaya Volcanic Rift Valley 41

#include <std.h>
#include "../defs.h"
inherit RIFT;

void create()
{
   ::create();
   set_exits(([
      "northwest":JGL"rift38",
      "east":JGL"rift42",
   ]));
}