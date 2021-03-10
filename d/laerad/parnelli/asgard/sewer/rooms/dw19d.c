#include <std.h>
#include "../lizard.h"
inherit DEEP2;

void create(){
::create();
set_exits(([
   "north":LROOMS+"dw9d",
   "northeast":LROOMS+"dw10d",
   "east":LROOMS+"dw20d",
   "southeast":LROOMS+"dw29d",
   "south":LROOMS+"dw28d",
   "southwest":LROOMS+"dw27d",
   "west":LROOMS+"dw18d",
   "up":LROOMS+"dw19",
   "down":LROOMS+"dw19dd"
 ]));
}
