#include <std.h>
#include "../lizard.h"
inherit DEEP2;

void create(){
::create();
set_exits(([
   "north":LROOMS+"dw29d",
   "west":LROOMS+"dw33d",
   "northwest":LROOMS+"dw28d",
   "up":LROOMS+"dw34",
   "down":LROOMS+"dw34dd"
 ]));
}
