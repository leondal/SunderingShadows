#include <std.h>
#include "graveyard.h"
inherit GRAVEYARD"cemetery";

void create(){
   ::create();
   set_exits(([
     "north":ROAD"froad7",
     "east":GRAVEYARD"cemetery2",
     "south":GRAVEYARD"cemetery4",
   ]));
}
