#include <std.h>
#include "../defs.h"
inherit INH+"shaft";

void create(){ 
   ::create();
   set_long("%^BOLD%^%^BLACK%^A sloped mining shaft%^RESET%^\n"+ ::query_long() +"%^ORANGE%^  The shaft "
"branches here, continuing downward to the north and northeast, while the upward slope leads "
"south.%^RESET%^\n");
   set_exits(([
     "south":MINES"shaft1d",
     "north":MINES"shaft1j",
     "northeast":MINES"shaft1f",
   ]));
}
