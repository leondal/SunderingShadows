#include <std.h>
#include "../defs.h"
inherit INH+"lower";

void create(){
   ::create();
   set_long("%^BOLD%^%^BLACK%^An underground mining tunnel%^RESET%^\n"+ ::query_long() +"%^BLUE%^  The tunnel "
"leads away to the west into darkness, but comes to an abrupt end to the east.%^RESET%^\n");
   set_exits(([
     "west":MINES"lower2j",
     "east":MINES"lower2l",
   ]));
}
