#include <std.h>
#include "../defs.h"
inherit INH+"lower";

void create(){
   ::create();
   set_long("%^BOLD%^%^BLACK%^An underground mining tunnel%^RESET%^\n"+ ::query_long() +"%^BLUE%^  The tunnel "
"leads away to the west and northeast into darkness.%^RESET%^\n");
   set_exits(([
     "west":MINES"lower1j",
     "northeast":MINES"lower1l",
   ]));
}
