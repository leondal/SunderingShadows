#include <std.h>
#include "../defs.h"
inherit INH+"shaft";

void create(){ 
   ::create();
   set_long("%^BOLD%^%^BLACK%^A sloped mining shaft%^RESET%^\n"+ ::query_long() +"%^ORANGE%^  The tunnel comes "
"to an abrupt halt here, seemingly unfinished, as though someone is still digging it.  The shaft travels back upwards toward the north.%^RESET%^\n");
   set_exits(([
     "north":MINES"shaft1s",
   ]));
}
