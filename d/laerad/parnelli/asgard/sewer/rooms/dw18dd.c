#include <std.h>
#include "../lizard.h"
inherit DEEP3;

void create(){
::create();
set_items(([
   "water":"Very cold and dark the water seeps inside your clothing like the kiss of death."
   ]));
set_exits(([
   "east":LROOMS+"dw19dd",
   "up":LROOMS+"dw18d"
 ]));
}
