#include <std.h>

#include "../lizard.h"
inherit MUSH;
void create(){
::create();
set_exits(([
   "north":LROOMS+"m6",
   "northeast":LROOMS+"m7",
   "east":LROOMS+"m11",
   "southeast":LROOMS+"m15",
   "south":LROOMS+"m14"
   ]));
}
