#include <std.h>
#include "../defs.h"
inherit INH+"shaft";

void create(){ 
   ::create();
   set_long("%^BOLD%^%^BLACK%^A sloped mining shaft%^RESET%^\n"+ ::query_long() +"%^ORANGE%^  The shaft "
"continues downward to the east, while the upward slope leads southwest, where you can see a branch in the "
"tunnel ahead.%^RESET%^\n");
   set_exits(([
     "southwest":MINES"shaft1e",
     "east":MINES"shaft1g",
   ]));
}
