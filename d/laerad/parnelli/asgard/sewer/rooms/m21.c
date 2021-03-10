#include <std.h>

#include "../lizard.h"
inherit MUSH;
void create(){
::create();
set_exits(([
   "north":LROOMS+"m19",
   "northeast":LROOMS+"p1",
   "east":LROOMS+"m22",
   "southeast":LROOMS+"m24",
   "northwest":LROOMS+"m18"
   ]));
}
