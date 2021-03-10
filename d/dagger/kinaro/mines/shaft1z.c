#include <std.h>
#include "../defs.h"
inherit INH+"shaft";

void create(){ 
   ::create();
   set_long("%^BOLD%^%^BLACK%^A sloped mining shaft%^RESET%^\n"+ ::query_long() +"%^ORANGE%^  This side tunnel "
"seems not to have much of a purpose, as though someone started digging this way and then thought better of "
"it, abandoning it as nothing more than a small alcove.  The shaft travels back upwards toward the "
"southeast.%^RESET%^\n");
   set_exits(([
     "southeast":MINES"shaft1w",
   ]));
}
