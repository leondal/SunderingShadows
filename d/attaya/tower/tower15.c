//Octothorpe (1/14/10)
//Attaya, Crystal Platform Room 15
//Original by Thundercracker

#include <std.h>
#include "../defs.h"
inherit INH+"platform1";

void create(){
   ::create();
   set_exits(([
      "southwest":TWR"tower14",
	  "southeast":TWR"tower16",
   ]));
}