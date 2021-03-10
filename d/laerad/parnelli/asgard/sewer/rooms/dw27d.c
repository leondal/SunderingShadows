#include <std.h>
#include "../lizard.h"
inherit DEEP2;

void create(){
::create();
set_exits(([
   "north":LROOMS+"dw18d",
   "northeast":LROOMS+"dw19d",
   "east":LROOMS+"dw28d",
   "southeast":LROOMS+"dw33d",
   "south":LROOMS+"dw32d",
   "up":LROOMS+"dw27"
   ]));
}
