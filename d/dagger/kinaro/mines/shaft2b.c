#include <std.h>
#include "../defs.h"
inherit INH+"shaft";

void create(){ 
   ::create();
   set_name("A flat mining shaft");
   set_short("%^BOLD%^%^BLACK%^A flat mining shaft%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^A flat mining shaft%^RESET%^\n"+ ::query_long() +"%^ORANGE%^  The shaft "
"continues on a flat level to the south and east, back toward the main tunnel, while another branch leads "
"upwards to the northwest.%^RESET%^\n");
   set_exits(([
     "east":MINES"shaft2a",
     "south":MINES"shaft2f",
     "northwest":MINES"shaft2c",
   ]));
}
