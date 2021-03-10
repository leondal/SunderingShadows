#include <std.h>
#include "../defs.h"
inherit INH+"shaft";

void create(){ 
   ::create();
   set_long("%^BOLD%^%^BLACK%^A sloped mining shaft%^RESET%^\n"+ ::query_long() +"%^ORANGE%^  It seems fairly "
"undisturbed here, as though no mining has taken place recently.  The shaft travels on a flat level from this "
"dead-end toward the northwest.%^RESET%^\n");
   set_exits(([
     "northwest":MINES"shaft1h",
   ]));
}
