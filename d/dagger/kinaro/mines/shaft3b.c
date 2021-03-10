#include <std.h>
#include "../defs.h"
inherit INH+"shaft";

void create(){ 
   ::create();
   set_long("%^BOLD%^%^BLACK%^A sloped mining shaft%^RESET%^\n"+ ::query_long() +"%^ORANGE%^  The shaft "
"continues downward to the east, curving around to the right out of sight, while the upward slope leads "
"south, back toward the main tunnel.%^RESET%^\n");
   set_exits(([
     "south":MINES"shaft3a",
     "east":MINES"shaft3c",
   ]));
}
