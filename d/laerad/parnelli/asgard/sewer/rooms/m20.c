#include <std.h>

#include "../lizard.h"
inherit MUSH;
void create(){
::create();
set_exits(([
   "north":LROOMS+"m17",
   "south":LROOMS+"m23",
   "southwest":LROOMS+"m22",
   "west":LROOMS+"p1",
   "northwest":LROOMS+"m16"
   ]));
}
