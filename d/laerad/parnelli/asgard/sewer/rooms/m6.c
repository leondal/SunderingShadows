#include <std.h>

#include "../lizard.h"
inherit MUSH;
void create(){
::create();
set_exits(([
   "north":LROOMS+"m2",
   "northeast":LROOMS+"m3",
   "east":LROOMS+"m7",
   "southeast":LROOMS+"m11",
   "south":LROOMS+"m10",
   "southwest":LROOMS+"m9",
   "west":LROOMS+"m5",
   "northwest":LROOMS+"w37"
   ]));
}
