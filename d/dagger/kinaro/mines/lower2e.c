#include <std.h>
#include "../defs.h"
inherit INH+"lower";

void create(){
   ::create();
   set_long("%^BOLD%^%^BLACK%^An underground mining tunnel%^RESET%^\n"+ ::query_long() +"%^BLUE%^  The tunnel "
"forks here, leading away to the northeast, northwest and south into darkness.%^RESET%^\n");
   set_exits(([
     "northwest":MINES"lower2f",
     "northeast":MINES"lower2d",
     "south":MINES"lower1a",
   ]));
}
