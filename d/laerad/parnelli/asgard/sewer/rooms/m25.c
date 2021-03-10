#include <std.h>

#include "../lizard.h"
inherit MUSH;
void create(){
::create();
set_exits(([
   "north":LROOMS+"m23",
   "west":LROOMS+"m24",
   "northwest":LROOMS+"m22"
  ]));
}
