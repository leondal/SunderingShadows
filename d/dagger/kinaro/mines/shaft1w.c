#include <std.h>
#include "../defs.h"
inherit INH+"shaft";

void create(){ 
   ::create();
   set_long("%^BOLD%^%^BLACK%^A sloped mining shaft%^RESET%^\n"+ ::query_long() +"%^ORANGE%^  The shaft "
"branches here, continuing downward to the southwest, while the upward slope leads to the east.  A small "
"alcove leads off the northwestern side of the tunnel.%^RESET%^\n");
   set_exits(([
     "east":MINES"shaft1v",
     "northwest":MINES"shaft1z",
     "southwest":MINES"shaft1x",
   ]));
}
