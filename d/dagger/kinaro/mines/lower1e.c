#include <std.h>
#include "../defs.h"
inherit INH+"lower";

void create(){
   ::create();
   set_long("%^BOLD%^%^BLACK%^An underground mining tunnel%^RESET%^\n"+ ::query_long() +"%^BLUE%^  The tunnel "
"forks here, leading away to the east, west and south into darkness.%^RESET%^\n");
   set_exits(([
     "west":MINES"lower1d",
     "east":MINES"lower1f",
     "south":MINES"lower1i",
   ]));
}
