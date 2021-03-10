#include <std.h>
#include "../defs.h"
inherit INH+"tunnel";

void create(){ 
   ::create();
   set_long("%^BOLD%^%^BLACK%^A dark tunnel%^RESET%^\n"+ ::query_long() +"%^BLUE%^  Just above you to the "
"west, the tunnel opens up onto empty air.%^RESET%^\n");
   set_exits(([
     "northwest":MID"tunnel02",
     "down":MID"tunnel04",
   ]));
}
