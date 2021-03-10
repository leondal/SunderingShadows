#include <std.h>
#include "../lizard.h"
inherit MUSH;
void create(){
::create();
set_exits(([
   "north":LROOMS+"m5",
   "northeast":LROOMS+"m6",
   "east":LROOMS+"m10",
   "southeast":LROOMS+"m14"
   ]));
}
