#include <std.h>
#include "../defs.h"
inherit INH+"lower";

void create(){
   ::create();
   set_long("%^BOLD%^%^BLACK%^An underground mining tunnel%^RESET%^\n"+ ::query_long() +"%^BLUE%^  The tunnel "
"comes to an abrupt end here, leading only to the northwest into darkness.%^RESET%^\n");
   set_exits(([
     "northwest":MINES"lower2b",
   ]));
}
