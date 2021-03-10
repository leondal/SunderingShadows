//Octothorpe (1/14/10)
//Attaya, Crystal Platform Room 73
//Original by Thundercracker

#include <std.h>
#include "../defs.h"
inherit INH+"platform1";

void create(){
   ::create();
   set_exits(([
      "northwest":TWR"tower71",
	  "northeast":TWR"tower70",
	  "southwest":TWR"tower54",
   ]));
}