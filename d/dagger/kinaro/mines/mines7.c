#include <std.h>
#include "../defs.h"
inherit INH+"tunnel";

void create(){ 
   ::create();
   set_long("%^BOLD%^%^BLACK%^A broad mining tunnel%^RESET%^\n"
+ ::query_long() +"  The tunnel continues toward the south and northeast.\n");
   set_exits(([
     "south":MINES"mines6",
     "northeast":MINES"mines8",
   ]));
}
