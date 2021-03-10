//Octothorpe (3/28/10)
//Attaya Volcanic Rift Valley 7

#include <std.h>
#include "../defs.h"
inherit RIFT;

void create()
{
   ::create();
   set_exits(([
      "southwest":JGL"rift6",
      "southeast":JGL"rift8",
      "northeast":JGL"rift9"	  
   ]));
}