#include <std.h>
#include "../defs.h"
inherit INH+"tunnel";

void create(){ 
   ::create();
   set_long("%^BOLD%^%^BLACK%^A broad mining tunnel%^RESET%^\n"
+ ::query_long() +"  The tunnel continues toward the north and southwest, "
"while a side tunnel branches away southeast into darkness.\n");
   set_exits(([
     "southwest":MINES"mines5",
     "north":MINES"mines7",
     "southeast":MINES"shaft1a",
   ]));
}
