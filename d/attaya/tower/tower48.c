//Octothorpe (1/14/10)
//Attaya, Crystal Platform Room 48
//Original by Thundercracker

#include <std.h>
#include "../defs.h"
inherit INH+"platform1";

void create(){
   ::create();
   set_exits(([
      "northwest":TWR"tower47",
	  "northeast":TWR"tower49",
   ]));
}