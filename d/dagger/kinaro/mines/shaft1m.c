#include <std.h>
#include "../defs.h"
inherit INH+"shaft";

void create(){ 
   ::create();
   set_long("%^BOLD%^%^BLACK%^A sloped mining shaft%^RESET%^\n"+ ::query_long() +"%^ORANGE%^  The shaft "
"continues on a flat level to both the northeast and east, where it seems to come to a dead-end.%^RESET%^\n");
   set_exits(([
     "northeast":MINES"shaft1l",
     "east":MINES"shaft1n",
   ]));
}
