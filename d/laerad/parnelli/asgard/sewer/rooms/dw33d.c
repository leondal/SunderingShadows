#include <std.h>
#include "../lizard.h"
inherit DEEP2;

void create(){
::create();
set_exits(([
   "north":LROOMS+"dw28d",
   "northeast":LROOMS+"dw29d",
   "east":LROOMS+"dw34d",
   "west":LROOMS+"dw32d",
   "northwest":LROOMS+"dw27d",
   "up":LROOMS+"dw33"
 ]));
}
