#include <std.h>

#include "../lizard.h"
inherit MUSH;
void create(){
::create();
set_exits(([
   "north":LROOMS+"w37",
   "northeast":LROOMS+"m2",
   "east":LROOMS+"m6",
   "southeast":LROOMS+"m10",
   "south":LROOMS+"m9"
   ]));
}
