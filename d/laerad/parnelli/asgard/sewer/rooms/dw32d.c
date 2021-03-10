#include <std.h>
#include "../lizard.h"
inherit DEEP2;

void create(){
::create();
set_exits(([
   "north":LROOMS+"dw27d",
   "northeast":LROOMS+"dw28d",
   "east":LROOMS+"dw33d",
   "up":LROOMS+"dw32"
   ]));
}
