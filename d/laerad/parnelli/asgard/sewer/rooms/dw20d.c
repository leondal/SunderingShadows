#include <std.h>
#include "../lizard.h"
inherit DEEP2;

void create(){
::create();
set_exits(([
   "north":LROOMS+"dw10d",
   "south":LROOMS+"dw29d",
   "southwest":LROOMS+"dw28d",
   "west":LROOMS+"dw19d",
   "northwest":LROOMS+"dw9d",
   "up":LROOMS+"dw9"
 ]));
}
