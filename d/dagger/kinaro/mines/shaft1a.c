#include <std.h>
#include "../defs.h"
inherit INH+"shaft";

void create(){ 
   ::create();
   set_long("%^BOLD%^%^BLACK%^A sloped mining shaft%^RESET%^\n"+ ::query_long() +"%^ORANGE%^  The shaft "
"continues downward to the east, curving around to the left out of sight, while the upward slope leads "
"northwest, back into the main tunnel.%^RESET%^\n");
   set_exits(([
     "northwest":MINES"mines6",
     "east":MINES"shaft1b",
   ]));
}
