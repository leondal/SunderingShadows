#include <std.h>
#include "../defs.h"
inherit INH+"shaft";

void create(){ 
   ::create();
   set_long("%^BOLD%^%^BLACK%^A sloped mining shaft%^RESET%^\n"+ ::query_long() +"%^ORANGE%^  The shaft "
"flattens out toward the south, curving around to the left out of sight, while the upward slope leads "
"west.%^RESET%^\n");
   set_exits(([
     "west":MINES"shaft1f",
     "south":MINES"shaft1h",
   ]));
}
