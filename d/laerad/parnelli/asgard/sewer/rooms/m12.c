#include <std.h>

#include "../lizard.h"
inherit MUSH;
void create(){
::create();
set_exits(([
   "north":LROOMS+"m8",
   "east":LROOMS+"m13",
   "southeast":LROOMS+"m17",
   "south":LROOMS+"m16",
   "southwest":LROOMS+"m15",
   "west":LROOMS+"m11",
   "northwest":LROOMS+"m7"
   ]));
}
