#include <std.h>

#include "../lizard.h"
inherit MUSH;
void create(){
::create();
set_exits(([
   "south":LROOMS+"m17",
   "southwest":LROOMS+"m16",
   "west":LROOMS+"m12",
   "northwest":LROOMS+"m8"
   ]));
}
