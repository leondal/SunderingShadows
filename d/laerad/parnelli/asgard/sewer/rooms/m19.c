#include <std.h>

#include "../lizard.h"
inherit MUSH;
void create(){
::create();
set_exits(([
   "north":LROOMS+"m15",
   "northeast":LROOMS+"m16",
   "east":LROOMS+"p1",
   "southeast":LROOMS+"m22",
   "south":LROOMS+"m21",
   "west":LROOMS+"m18",
   "northwest":LROOMS+"m14"
   ]));
}
