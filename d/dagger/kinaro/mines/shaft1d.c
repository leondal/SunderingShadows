#include <std.h>
#include "../defs.h"
inherit INH+"shaft";

void create(){ 
   ::create();
   set_long("%^BOLD%^%^BLACK%^A sloped mining shaft%^RESET%^\n"+ ::query_long() +"%^ORANGE%^  The shaft "
"continues downward to the north, where you can see a branch in the tunnel ahead, while the upward slope leads "
"southwest.%^RESET%^\n");
   set_exits(([
     "southwest":MINES"shaft1c",
     "north":MINES"shaft1e",
   ]));
}
