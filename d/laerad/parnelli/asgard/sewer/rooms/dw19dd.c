#include <std.h>
#include "../lizard.h"
inherit DEEP3;

void create(){
::create();
set_items(([
   "water":"Very cold and dark the water seeps inside your clothing like the kiss of death."
   ]));
set_exits(([
   "west":LROOMS+"dw18dd",
   "south":LROOMS+"dw28dd",
   "up":LROOMS+"dw19d"
 ]));
}
