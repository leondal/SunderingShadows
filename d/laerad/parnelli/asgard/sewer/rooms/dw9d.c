#include <std.h>
#include "../lizard.h"
inherit DEEP2;

void create(){
::create();
set_exits(([
   "east":LROOMS+"dw10d",
   "southeast":LROOMS+"dw20d",
   "south":LROOMS+"dw19d",
   "southwest":LROOMS+"dw18d",
   "up":LROOMS+"dw9"
 ]));
}
