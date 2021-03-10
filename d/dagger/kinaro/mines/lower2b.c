#include <std.h>
#include "../defs.h"
inherit INH+"lower";

void create(){
   ::create();
   set_long("%^BOLD%^%^BLACK%^An underground mining tunnel%^RESET%^\n"+ ::query_long() +"%^BLUE%^  The tunnel "
"leads away to the south into darkness, but comes to an abrupt end to the southeast.%^RESET%^\n");
   set_exits(([
     "south":MINES"lower2c",
     "southeast":MINES"lower2a",
   ]));
}
