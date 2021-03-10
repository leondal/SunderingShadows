#include <std.h>
#include "../../newbie.h"

inherit "/d/newbie/rooms/road/cemetery1";

void create(){
   ::create();
   set_exits(([
	"north":ROAD"cemetery1",
      	"east":ROAD"cemetery5",
      	"northeast":ROAD"cemetery2",
   ]));
}
