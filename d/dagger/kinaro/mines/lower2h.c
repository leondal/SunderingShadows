#include <std.h>
#include "../defs.h"
inherit INH+"lower";

void create(){
   ::create();
   set_long("%^BOLD%^%^BLACK%^An underground mining tunnel%^RESET%^\n"+ ::query_long() +"%^BLUE%^  The tunnel "
"leads away to the northeast and west into darkness.%^RESET%^\n");
   set_exits(([
     "northeast":MINES"lower2g",
     "west":MINES"lower2i",
   ]));
}
