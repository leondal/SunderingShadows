#include <std.h>
#include "../../newbie.h"

inherit "/d/newbie/rooms/road/cemetery1";

void create(){
   ::create();
   set_exits(([
		"west":ROAD"cemetery1",
      "east":ROAD"cemetery3",
      "south":ROAD"cemetery5",
      "southeast":ROAD"cemetery6",
      "southwest":ROAD"cemetery4",
   ]));
}
