//Octothorpe (5/5/16)
//Attaya Volcanic Rift Valley 13

#include <std.h>
#include "../defs.h"
inherit RIFT;

void create()
{
   ::create();
   set_exits(([
      "southwest":JGL"rift11",
   ]));
}

/*Add climb/searchable up exit to phoenix room - Octothorpe*/