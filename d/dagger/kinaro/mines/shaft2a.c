#include <std.h>
#include "../defs.h"
inherit INH+"shaft";

void create(){ 
   ::create();
   set_name("A flat mining shaft");
   set_short("%^BOLD%^%^BLACK%^A flat mining shaft%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^A flat mining shaft%^RESET%^\n"+ ::query_long() +"%^ORANGE%^  The shaft "
"continues on a flat level to the west, where you can see a branch in the tunnel ahead, and to the northeast, "
"back into the main tunnel.%^RESET%^\n");
   set_exits(([
     "northeast":MINES"mines2",
     "west":MINES"shaft2b",
   ]));
}
