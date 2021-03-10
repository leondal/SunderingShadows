#include <std.h>

#include "../lizard.h"
inherit MUSH;
void create(){
::create();
set_exits(([
   "northeast":LROOMS+"m1",
   "east":LROOMS+"m3",
   "southeast":LROOMS+"m7",
   "south":LROOMS+"m6",
   "southwest":LROOMS+"m5",
   "west":LROOMS+"w37",
   "northwest":LROOMS+"w36"
   ]));
}
