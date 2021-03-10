#include <std.h>
#include "../defs.h"
inherit INH+"tunnel";

void create(){ 
   ::create();
   set_long("%^BOLD%^%^BLACK%^A dark tunnel%^RESET%^\n"+ ::query_long() +"%^BLUE%^  A little further east, it "
"seems the tunnel opens up into a large cavern of some sort.%^RESET%^\n");
   set_exits(([
     "up":MID"tunnel07",
     "northeast":MID"tunnel09",
   ]));
}
