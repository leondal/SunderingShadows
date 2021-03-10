#include <std.h>
#include "../defs.h"
inherit INH+"shaft";

void create(){ 
   ::create();
   set_long("%^BOLD%^%^BLACK%^A sloped mining shaft%^RESET%^\n"+ ::query_long() +"%^ORANGE%^  The shaft "
"travels on a flat level in both directions, curving around out of sight to the north, while to the southeast "
"it seems to reach a dead-end.%^RESET%^\n");
   set_exits(([
     "north":MINES"shaft1g",
     "southeast":MINES"shaft1i",
   ]));
}
