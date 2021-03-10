#include <std.h>
#include "../defs.h"
inherit INH+"chasm";

void create(){ 
   ::create();
   set_long("%^MAGENTA%^Within the Wailing Chasm%^RESET%^\n"+ ::query_long() +"%^BLUE%^  A narrow %^WHITE%^"
"stone bridge %^BLUE%^meets the wall here, spanning out across the chasm, while a short ledge leads further "
"south.%^RESET%^\n");
   add_item(({"bridge","span"}),"%^BLUE%^A narrow %^WHITE%^stone bridge %^BLUE%^meets the wall here, that "
"spans across the great chasm, disappearing into %^BOLD%^%^BLACK%^darkness %^RESET%^%^BLUE%^toward the other "
"side.%^RESET%^");
   set_exits(([
     "northwest":MID"chasm26",
     "south":MID"chasm28",
     "bridge":MID"bridge01",
   ]));
   set_pre_exit_functions(({"northwest","bridge","south"}),({"GoThroughDoor","GoThroughDoor","GoThroughDoor"}));
}

