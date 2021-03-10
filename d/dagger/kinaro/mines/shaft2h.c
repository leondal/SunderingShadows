#include <std.h>
#include "../defs.h"
inherit INH+"shaft";

void create(){ 
   ::create();
   set_name("A flat mining shaft");
   set_short("%^BOLD%^%^BLACK%^A flat mining shaft%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^A flat mining shaft%^RESET%^\n"+ ::query_long() +"%^ORANGE%^  It seems fairly "
"undisturbed here, as though no mining has taken place recently.  The shaft travels on a flat level from this "
"dead-end toward the west.%^RESET%^\n");
   set_exits(([
     "west":MINES"shaft2g",
   ]));
}
