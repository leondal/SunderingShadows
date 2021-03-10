#include <std.h>
#include "../defs.h"
inherit INH+"shaft";

void create(){ 
   ::create();
   set_long("%^BOLD%^%^BLACK%^A sloped mining shaft%^RESET%^\n"+ ::query_long() +"%^ORANGE%^  The shaft "
"continues downward to the northwest, while the upward slope leads south.  You can see a branch in the tunnel "
"ahead in both directions.%^RESET%^\n");
   set_exits(([
     "northwest":MINES"shaft1k",
     "south":MINES"shaft1e",
   ]));
}
