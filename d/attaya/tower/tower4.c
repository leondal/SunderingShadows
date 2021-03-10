//Octothorpe (1/14/10)
//Attaya, Crystal Platform Room 4
//Original by Thundercracker

#include <std.h>
#include "../defs.h"
inherit INH+"platform1";

void create(){
   ::create();
   set_exits(([
      "southwest":TWR"tower5",
	  "northeast":TWR"tower3",
   ]));
}