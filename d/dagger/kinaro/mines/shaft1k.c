#include <std.h>
#include "../defs.h"
inherit INH+"shaft";

void create(){ 
   ::create();
   set_long("%^BOLD%^%^BLACK%^A sloped mining shaft%^RESET%^\n"+ ::query_long() +"%^ORANGE%^  The shaft "
"branches here, continuing downward to the northwest, while a flat-level tunnel branches west, and the upward "
"slope leads to the southeast.%^RESET%^\n");
   set_exits(([
     "southeast":MINES"shaft1j",
     "west":MINES"shaft1l",
     "northwest":MINES"shaft1o",
   ]));
}
