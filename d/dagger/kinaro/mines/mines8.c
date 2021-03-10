#include <std.h>
#include "../defs.h"
inherit INH+"tunnel";

void create(){ 
   ::create();
   set_long("%^BOLD%^%^BLACK%^A broad mining tunnel%^RESET%^\n"
+ ::query_long() +"  The tunnel continues toward the east and southwest, "
"while a side tunnel branches away northwest into darkness.\n");
   set_exits(([
     "southwest":MINES"mines7",
     "east":MINES"mines9",
     "northwest":MINES"shaft3a",
   ]));
}
