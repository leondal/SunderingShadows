//Octothorpe (3/28/10)
//Attaya Jungle Path 33
//Original by Thundercracker

#include <std.h>
#include "../defs.h"
inherit RIFT;

void create(){
   ::create();
   set_exits(([
      "up":JGL"jun32",
      "northeast":JGL"rift1",
	  "east":JGL"rift2",
	  "southeast":JGL"rift3"	  
   ]));
}
