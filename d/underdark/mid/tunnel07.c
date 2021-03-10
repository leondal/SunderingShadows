#include <std.h>
#include "../defs.h"
inherit INH+"tunnel";

void create(){ 
   ::create();
   set_long("%^BOLD%^%^BLACK%^A dark tunnel%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"tunnel06",
     "down":MID"tunnel08",
   ]));
}
