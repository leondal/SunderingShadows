#include <std.h>
#include "../defs.h"
inherit INH+"shaft";

void create(){ 
   ::create();
   set_long("%^BOLD%^%^BLACK%^A sloped mining shaft%^RESET%^\n"+ ::query_long() +"%^ORANGE%^  The shaft "
"continues downward to the north, while the upward slope leads southeast, where you can see a branch in the "
"tunnel ahead.%^RESET%^\n");
   set_exits(([
     "southeast":MINES"shaft1q",
     "north":MINES"shaft1v",
   ]));
}
