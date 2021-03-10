//Octothorpe (1/14/10)
//Attaya, Crystal Platform Room 37
//Original by Thundercracker

#include <std.h>
#include "../defs.h"
inherit INH+"platform1";

void create(){
   ::create();
   set_exits(([
      "southwest":TWR"tower36",
	  "northeast":TWR"tower38",
   ]));
}