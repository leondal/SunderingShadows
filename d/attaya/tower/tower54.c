//Octothorpe (1/14/10)
//Attaya, Crystal Platform Room 54
//Original by Thundercracker

#include <std.h>
#include "../defs.h"
inherit INH+"platform1";

void create(){
   ::create();
   set_exits(([
      "southeast":TWR"tower56",
      "southwest":TWR"tower53",
	  "northeast":TWR"tower73",
   ]));
}