#include <std.h>

#include "../lizard.h"
inherit MUSH;
void create(){
::create();
set_exits(([
   "north":LROOMS+"m22",
   "northeast":LROOMS+"m23",
   "east":LROOMS+"m25",
   "northwest":LROOMS+"m21"
   ]));
}
