#include <std.h>

#include "../lizard.h"
inherit MUSH;
void create(){
::create();
set_exits(([
   "south":LROOMS+"m8",
   "southwest":LROOMS+"m7",
   "west":LROOMS+"m3",
   "northwest":LROOMS+"m1"
   ]));
}
