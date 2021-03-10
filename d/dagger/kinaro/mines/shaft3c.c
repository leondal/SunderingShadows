#include <std.h>
#include "../defs.h"
inherit INH+"shaft";

void create(){ 
   ::create();
   set_long("%^BOLD%^%^BLACK%^A sloped mining shaft%^RESET%^\n"+ ::query_long() +"%^ORANGE%^  The shaft "
"continues downward to the southwest, where it seems to reach a dead-end, while the upward slope leads "
"west.%^RESET%^\n");
   set_exits(([
     "west":MINES"shaft3b",
     "southwest":MINES"shaft3d",
   ]));
}
