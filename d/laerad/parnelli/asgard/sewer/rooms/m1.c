#include <std.h>

#include "../lizard.h"
inherit MUSH;
void create(){
::create();
set_exits(([
   "southeast":LROOMS+"m4",
   "south":LROOMS+"m3",
   "southwest":LROOMS+"m2"
   ]));
}
