#include <std.h>
#include "../lizard.h"
inherit DEEP2;

void create(){
::create();
set_exits(([
   "north":LROOMS+"dw19d",
   "northeast":LROOMS+"dw20d",
   "east":LROOMS+"dw29d",
   "southeast":LROOMS+"dw34d",
   "south":LROOMS+"dw33d",
   "southwest":LROOMS+"dw32d",
   "west":LROOMS+"dw27d",
   "northwest":LROOMS+"dw18d",
   "up":LROOMS+"dw28",
   "down":LROOMS+"dw28dd"
 ]));
}
