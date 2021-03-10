#include <std.h>

#include "../lizard.h"
inherit MUSH;
void create(){
::create();
set_exits(([
   "north":LROOMS+"m4",
   "southeast":LROOMS+"m13",
   "south":LROOMS+"m12",
   "southwest":LROOMS+"m11",
   "west":LROOMS+"m7",
   "northwest":LROOMS+"m3"
   ]));
}
