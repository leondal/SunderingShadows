#include <std.h>
#include "../defs.h"
inherit INH+"shaft";

void create(){ 
   ::create();
   set_long("%^BOLD%^%^BLACK%^A sloped mining shaft%^RESET%^\n"+ ::query_long() +"%^ORANGE%^  The shaft "
"continues downward to the north, curving around to the left out of sight, while the upward slope leads "
"southeast, back into the main tunnel.%^RESET%^\n");
   set_exits(([
     "southeast":MINES"mines8",
     "north":MINES"shaft3b",
   ]));
}
