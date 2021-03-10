#include <std.h>
#include "../lizard.h"
inherit DEEP2;

void create(){
::create();
set_exits(([
   "north":LROOMS+"dw20d",
   "south":LROOMS+"dw34d",
   "southwest":LROOMS+"dw33d",
   "west":LROOMS+"dw28d",
   "northwest":LROOMS+"dw19d",
   "up":LROOMS+"dw29"
 ]));
}
