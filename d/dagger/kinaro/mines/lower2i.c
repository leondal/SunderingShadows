#include <std.h>
#include "../defs.h"
inherit INH+"lower";

void create(){
   ::create();
   set_long("%^BOLD%^%^BLACK%^An underground mining tunnel%^RESET%^\n"+ ::query_long() +"%^BLUE%^  The tunnel "
"forks here, leading away to the east, west and southwest into darkness.%^RESET%^\n");
   set_exits(([
     "west":MINES"lower2m",
     "east":MINES"lower2h",
     "southwest":MINES"lower2j",
   ]));
}
