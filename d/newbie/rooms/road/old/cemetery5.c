#include <std.h>
#include "../../newbie.h"

inherit "/d/newbie/rooms/road/cemetery1";

void create(){
   ::create();
   set_exits(([
		"west":ROAD"cemetery4",
      "east":ROAD"cemetery6",
      "northwest":ROAD"cemetery1",
      "north":ROAD"cemetery2",
      "northeast":ROAD"cemetery3",
   ]));
}
