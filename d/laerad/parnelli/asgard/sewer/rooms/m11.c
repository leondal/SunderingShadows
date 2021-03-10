#include <std.h>

#include "../lizard.h"
inherit MUSH;
void create(){
::create();
set_exits(([
   "north":LROOMS+"m7",
   "northeast":LROOMS+"m8",
   "east":LROOMS+"m12",
   "southeast":LROOMS+"m16",
   "south":LROOMS+"m15",
   "southwest":LROOMS+"m14",
   "west":LROOMS+"m10",
   "northwest":LROOMS+"m6"
   ]));
}
