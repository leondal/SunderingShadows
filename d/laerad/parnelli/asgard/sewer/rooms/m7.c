#include <std.h>

#include "../lizard.h"
inherit MUSH;
void create(){
::create();
set_exits(([
   "north":LROOMS+"m3",
   "northeast":LROOMS+"m4",
   "east":LROOMS+"m8",
   "southeast":LROOMS+"m12",
   "south":LROOMS+"m11",
   "southwest":LROOMS+"m10",
   "west":LROOMS+"m6",
   "northwest":LROOMS+"m2"
   ]));
}
