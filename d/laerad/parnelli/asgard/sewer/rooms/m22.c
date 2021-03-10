#include <std.h>

#include "../lizard.h"
inherit MUSH;
void create(){
::create();
set_exits(([
   "north":LROOMS+"p1",
   "northeast":LROOMS+"m20",
   "east":LROOMS+"m23",
   "southeast":LROOMS+"m25",
   "south":LROOMS+"m24",
   "west":LROOMS+"m21",
   "northwest":LROOMS+"m19"
   ]));
}
