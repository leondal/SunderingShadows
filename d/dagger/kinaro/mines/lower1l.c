#include <std.h>
#include "../defs.h"
inherit INH+"lower";

void create(){
   ::create();
   set_long("%^BOLD%^%^BLACK%^An underground mining tunnel%^RESET%^\n"+ ::query_long() +"%^BLUE%^  The tunnel "
"leads away to the southwest into darkness, but comes to an abrupt end to the east.%^RESET%^\n");
   set_exits(([
     "southwest":MINES"lower1k",
     "east":MINES"lower1m",
   ]));
}
