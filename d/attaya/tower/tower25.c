//Octothorpe (1/14/10)
//Attaya, Crystal Platform Room 25
//Original by Thundercracker

#include <std.h>
#include "../defs.h"
inherit INH+"platform1";

void create(){
   ::create();
   set_exits(([
      "southwest":TWR"tower23",
	  "northeast":TWR"tower26",
   ]));
}