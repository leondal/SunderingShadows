//Octothorpe (1/14/10)
//Attaya, Crystal Platform Room 2
//Original by Thundercracker

#include <std.h>
#include "../defs.h"
inherit INH+"platform1";

void create(){
   ::create();
   set_exits(([
      "southwest":TWR"tower3",
	  "northeast":TWR"tower1",
   ]));
}