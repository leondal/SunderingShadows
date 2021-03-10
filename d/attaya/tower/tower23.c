//Octothorpe (1/14/10)
//Attaya, Crystal Platform Room 23
//Original by Thundercracker

#include <std.h>
#include "../defs.h"
inherit INH+"platform1";

void create(){
   ::create();
   set_exits(([
      "southeast":TWR"tower24",
	  "southwest":TWR"tower22",
	  "northeast":TWR"tower25",
   ]));
}