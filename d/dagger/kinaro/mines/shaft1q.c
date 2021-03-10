#include <std.h>
#include "../defs.h"
inherit INH+"shaft";

void create(){ 
   ::create();
   set_long("%^BOLD%^%^BLACK%^A sloped mining shaft%^RESET%^\n"+ ::query_long() +"%^ORANGE%^  The shaft "
"branches here, continuing downward to the northwest and southeast, while the upward slope leads to the "
"east.%^RESET%^\n");
   set_exits(([
     "east":MINES"shaft1p",
     "northwest":MINES"shaft1u",
     "southeast":MINES"shaft1r",
   ]));
}
