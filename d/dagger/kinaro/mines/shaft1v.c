#include <std.h>
#include "../defs.h"
inherit INH+"shaft";

void create(){ 
   ::create();
   set_long("%^BOLD%^%^BLACK%^A sloped mining shaft%^RESET%^\n"+ ::query_long() +"%^ORANGE%^  The shaft "
"continues downward to the west, where you can see a branch in the tunnel ahead, while the upward slope leads "
"south.%^RESET%^\n");
   set_exits(([
     "south":MINES"shaft1u",
     "west":MINES"shaft1w",
   ]));
}
