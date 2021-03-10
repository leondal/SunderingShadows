#include <std.h>
#include "../defs.h"
inherit INH+"shaft";

void create(){ 
   ::create();
   set_long("%^BOLD%^%^BLACK%^A sloped mining shaft%^RESET%^\n"+ ::query_long() +"%^ORANGE%^  The shaft "
"continues downward to the south, where it seems to reach a dead-end, while the upward slope leads "
"east.%^RESET%^\n");
   set_exits(([
     "east":MINES"shaft1r",
     "south":MINES"shaft1t",
   ]));
}
