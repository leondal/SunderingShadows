#include <std.h>
#include "../defs.h"
inherit INH+"shaft";

void create(){ 
   ::create();
   set_long("%^BOLD%^%^BLACK%^A sloped mining shaft%^RESET%^\n"+ ::query_long() +"%^ORANGE%^  The shaft "
"continues on a flat level to both the southwest and east, where you can see a branch in the tunnel "
"ahead.%^RESET%^\n");
   set_exits(([
     "east":MINES"shaft1k",
     "southwest":MINES"shaft1m",
   ]));
}
