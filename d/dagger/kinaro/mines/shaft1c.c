#include <std.h>
#include "../defs.h"
inherit INH+"shaft";

void create(){ 
   ::create();
   set_long("%^BOLD%^%^BLACK%^A sloped mining shaft%^RESET%^\n"+ ::query_long() +"%^ORANGE%^  The shaft "
"continues downward to the northeast, curving around to the left out of sight, while the upward slope leads "
"southwest.%^RESET%^\n");
   set_exits(([
     "southwest":MINES"shaft1b",
     "northeast":MINES"shaft1d",
   ]));
}
