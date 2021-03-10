#include <std.h>

#include "../lizard.h"
inherit MUSH;
void create(){
::create();
set_exits(([
   "north":LROOMS+"m20",
   "south":LROOMS+"m25",
   "southwest":LROOMS+"m24",
   "west":LROOMS+"m22",
   "northwest":LROOMS+"p1"
   ]));
}
