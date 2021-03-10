#include <std.h>
#include "../defs.h"
inherit INH+"lower";

void create(){
   ::create();
   set_long("%^BOLD%^%^BLACK%^An underground mining tunnel%^RESET%^\n"+ ::query_long() +"%^BLUE%^  The tunnel "
"leads away to the north and south into darkness.%^RESET%^\n");
   set_exits(([
     "north":MINES"lower1a",
     "south":MINES"lower1c",
   ]));
}
