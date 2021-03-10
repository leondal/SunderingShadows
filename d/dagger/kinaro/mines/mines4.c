#include <std.h>
#include "../defs.h"
inherit INH+"tunnel";

void create(){ 
   ::create();
   set_long("%^BOLD%^%^BLACK%^A broad mining tunnel%^RESET%^\n"
+ ::query_long() +"  The tunnel continues toward the east and west, while a "
"side tunnel branches away south into darkness.\n");
   set_exits(([
     "west":MINES"mines3",
     "east":MINES"mines5",
     "south":MINES"shaft0",
   ]));
}
