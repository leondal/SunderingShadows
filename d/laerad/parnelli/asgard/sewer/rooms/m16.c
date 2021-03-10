#include <std.h>

#include "../lizard.h"
inherit MUSH;
void create(){
::create();
set_exits(([
   "north":LROOMS+"m12",
   "northeast":LROOMS+"m13",
   "east":LROOMS+"m17",
   "southeast":LROOMS+"m20",
   "south":LROOMS+"p1",
   "southwest":LROOMS+"m19",
   "west":LROOMS+"m15",
   "northwest":LROOMS+"m11"
   ]));
}
