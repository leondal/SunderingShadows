#include <std.h>
#include "../lizard.h"
inherit DEEP2;

void create(){
::create();
set_exits(([
   "northeast":LROOMS+"dw9d",
   "east":LROOMS+"dw19d",
   "southeast":LROOMS+"dw28d",
   "south":LROOMS+"dw27d",
   "down":LROOMS+"dw18dd",
   "up":LROOMS+"dw18"
 ]));
}
