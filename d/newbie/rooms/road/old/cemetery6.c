#include <std.h>
#include "../../newbie.h"

inherit "/d/newbie/rooms/road/cemetery1";

void create(){
   ::create();
   set_exits(([
		"west":ROAD"cemetery5",
      "north":ROAD"cemetery3",
      "northwest":ROAD"cemetery2",
   ]));
}
