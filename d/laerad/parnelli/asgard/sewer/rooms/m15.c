#include <std.h>

#include "../lizard.h"
inherit MUSH;
void create(){
::create();
set_exits(([
   "north":LROOMS+"m11",
   "northeast":LROOMS+"m12",
   "east":LROOMS+"m16",
   "southeast":LROOMS+"p1",
   "south":LROOMS+"m19",
   "southwest":LROOMS+"m18",
   "west":LROOMS+"m14",
   "northwest":LROOMS+"m10"
   ]));
}
