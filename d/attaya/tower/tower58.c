//Octothorpe (1/14/10)
//Attaya, Crystal Platform Room 58
//Original by Thundercracker

#include <std.h>
#include "../defs.h"
inherit INH+"platform1";

void create(){
   ::create();
   set_exits(([
      "southwest":TWR"tower59",
	  "northeast":TWR"tower57",
   ]));
}