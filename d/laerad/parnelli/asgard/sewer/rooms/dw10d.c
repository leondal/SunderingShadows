#include <std.h>
#include "../lizard.h"
inherit DEEP2;

void create(){
::create();
set_exits(([
   "south":LROOMS+"dw20d",
   "southwest":LROOMS+"dw19d",
   "west":LROOMS+"dw9d",
   "up":LROOMS+"dw10"
 ]));
}
