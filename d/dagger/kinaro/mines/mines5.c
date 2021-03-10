#include <std.h>
#include "../defs.h"
inherit INH+"tunnel";

void create(){ 
   ::create();
   set_long("%^BOLD%^%^BLACK%^A broad mining tunnel%^RESET%^\n"
+ ::query_long() +"  The tunnel continues toward the west and northeast.\n");
   set_exits(([
     "west":MINES"mines4",
     "northeast":MINES"mines6",
   ]));
}
