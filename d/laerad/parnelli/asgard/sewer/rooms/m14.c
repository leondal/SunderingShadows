#include <std.h>

#include "../lizard.h"
inherit MUSH;
void create(){
::create();
set_exits(([
   "north":LROOMS+"m10",
   "northeast":LROOMS+"m11",
   "east":LROOMS+"m15",
   "southeast":LROOMS+"m19",
   "south":LROOMS+"m18",
   "northwest":LROOMS+"m9"
   ]));
}
