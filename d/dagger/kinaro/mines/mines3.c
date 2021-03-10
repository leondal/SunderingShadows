#include <std.h>
#include "../defs.h"
inherit INH+"tunnel";

void create(){ 
   ::create();
   set_long("%^BOLD%^%^BLACK%^A broad mining tunnel%^RESET%^\n"
+ ::query_long() +"  The tunnel continues toward the east and northwest, "
"where you can see a hint of %^BOLD%^%^WHITE%^light %^RESET%^against the "
"darkness of the tunnel.\n");
   set_exits(([
     "northwest":MINES"mines2",
     "east":MINES"mines4",
   ]));
}
