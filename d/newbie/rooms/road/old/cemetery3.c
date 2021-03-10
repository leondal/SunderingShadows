#include <std.h>
#include "../../newbie.h"

inherit "/d/newbie/rooms/road/cemetery1";

void create(){
   ::create();
   set_exits(([
		"west":ROAD"cemetery2",
      "south":ROAD"cemetery6",
      "southwest":ROAD"cemetery5",
   ]));
}
