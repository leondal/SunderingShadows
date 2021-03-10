//Octothorpe (1/14/10)
//Attaya, Crystal Platform Room 6
//Original by Thundercracker

#include <std.h>
#include "../defs.h"
inherit INH+"platform1";

void create(){
   ::create();
   set_exits(([
      "southeast":TWR"tower7",
	  "northeast":TWR"tower5",
   ]));
}