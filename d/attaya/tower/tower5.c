//Octothorpe (1/14/10)
//Attaya, Crystal Platform Room 5
//Original by Thundercracker

#include <std.h>
#include "../defs.h"
inherit INH+"platform1";

void create(){
   ::create();
   set_exits(([
      "southwest":TWR"tower6",
	  "northeast":TWR"tower4",
   ]));
}