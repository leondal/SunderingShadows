//Octothorpe (1/14/10)
//Attaya, Crystal Platform Room 12
//Original by Thundercracker

#include <std.h>
#include "../defs.h"
inherit INH+"platform1";

void create(){
   ::create();
   set_exits(([
      "southeast":TWR"tower11",
	  "northeast":TWR"tower13",
   ]));
}