#include <std.h>

#include "../lizard.h"
inherit MUSH;
void create(){
::create();
set_exits(([
   "north":LROOMS+"m14",
   "northeast":LROOMS+"m15",
   "east":LROOMS+"m19",
   "southeast":LROOMS+"m21"
   ]));
}
