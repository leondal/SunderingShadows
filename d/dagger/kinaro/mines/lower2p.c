#include <std.h>
#include "../defs.h"
inherit INH+"lower";

void create(){
   ::create();
   set_long("%^BOLD%^%^BLACK%^An underground mining tunnel%^RESET%^\n"+ ::query_long() +"%^BLUE%^  The tunnel "
"leads away to the northwest into darkness, but comes to an abrupt end to the south.%^RESET%^\n");
   set_exits(([
     "northwest":MINES"lower2o",
     "south":MINES"lower2q",
   ]));
}
