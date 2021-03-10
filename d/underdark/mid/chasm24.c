#include <std.h>
#include "../defs.h"
inherit INH+"chasm";

void create(){ 
   ::create();
   set_long("%^MAGENTA%^Within the Wailing Chasm%^RESET%^\n"+ ::query_long() +"%^BLUE%^  A little to the "
"south, the outline of a %^WHITE%^bridge %^BLUE%^comes into focus, spanning out across the chasm.%^RESET%^\n");
   add_item(({"bridge","span"}),"%^BLUE%^A short distance to the south, you can just make out the outline of a "
"%^WHITE%^stone bridge %^BLUE%^that spans across the great chasm, disappearing into %^BOLD%^%^BLACK%^darkness "
"%^RESET%^%^BLUE%^toward the other side.%^RESET%^");
   set_exits(([
     "northwest":MID"chasm23",
     "southeast":MID"chasm25",
   ]));
   set_pre_exit_functions(({"northwest","southeast"}),({"GoThroughDoor","GoThroughDoor"}));
}
