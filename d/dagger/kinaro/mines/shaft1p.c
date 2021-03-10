#include <std.h>
#include "../defs.h"
inherit INH+"shaft";

void create(){ 
   ::create();
   set_long("%^BOLD%^%^BLACK%^A sloped mining shaft%^RESET%^\n"+ ::query_long() +"%^ORANGE%^  The shaft "
"continues downward to the west, where you can see a branch in the tunnel ahead, while the upward slope leads "
"east.%^RESET%^\n");
   set_exits(([
     "east":MINES"shaft1o",
     "west":MINES"shaft1q",
   ]));
}
