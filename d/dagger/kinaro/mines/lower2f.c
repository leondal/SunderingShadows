#include <std.h>
#include "../defs.h"
inherit INH+"lower";

void create(){
   ::create();
   set_long("%^BOLD%^%^BLACK%^An underground mining tunnel%^RESET%^\n"+ ::query_long() +"%^BLUE%^  The tunnel "
"leads away to the south and southeast into darkness.%^RESET%^\n");
   set_exits(([
     "southeast":MINES"lower2e",
     "south":MINES"lower2g",
   ]));
}
