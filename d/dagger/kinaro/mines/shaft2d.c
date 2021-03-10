#include <std.h>
#include "../defs.h"
inherit INH+"shaft";

void create(){ 
   ::create();
   set_name("A flat mining shaft");
   set_short("%^BOLD%^%^BLACK%^A flat mining shaft%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^A flat mining shaft%^RESET%^\n"+ ::query_long() +"%^ORANGE%^  The shaft "
"travels on a flat level in both directions, curving around out of sight to the south, while to the southeast "
"it seems to reach a dead-end.%^RESET%^\n");
   set_exits(([
     "south":MINES"shaft2c",
     "southeast":MINES"shaft2e",
   ]));
}
