#include <std.h>

#include "../lizard.h"
inherit MUSH;
void create(){
::create();
set_exits(([
   "north":LROOMS+"m13",
   "south":LROOMS+"m20",
   "southwest":LROOMS+"p1",
   "west":LROOMS+"m16",
   "northwest":LROOMS+"m12"
   ]));
}
