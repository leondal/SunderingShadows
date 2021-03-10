#include <std.h>

#include "../lizard.h"
inherit MUSH;
void create(){
::create();
set_exits(([
   "north":LROOMS+"m1",
   "east":LROOMS+"m4",
   "southeast":LROOMS+"m8",
   "south":LROOMS+"m7",
   "southwest":LROOMS+"m6",
   "west":LROOMS+"m2"
   ]));
}
