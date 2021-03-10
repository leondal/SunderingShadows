#include <std.h>
#include "../defs.h"
inherit INH+"chasm";

void create(){ 
   ::create();
   set_long("%^MAGENTA%^Within the Wailing Chasm%^RESET%^\n"+ ::query_long() +"%^BLUE%^  A little to the "
"north, the outline of a %^WHITE%^bridge %^BLUE%^comes into focus, spanning out across the chasm, while this short ledge "
"leads to a dead end just to the southeast.%^RESET%^\n");
   add_item(({"bridge","span"}),"%^BLUE%^A short distance to the north, you can just make out the outline of a "
"%^WHITE%^stone bridge %^BLUE%^that spans across the great chasm, disappearing into %^BOLD%^%^BLACK%^darkness "
"%^RESET%^%^BLUE%^toward the other side.%^RESET%^");
   set_exits(([
     "north":MID"chasm27",
     "southeast":MID"chasm29",
   ]));
   set_climb_exits(([
     "descend":({"/d/underdark/mid/questcave",15,roll_dice(2,10),100}),
   ]));
   set_pre_exit_functions(({"north","southeast"}),({"GoThroughDoor","GoThroughDoor"}));
}

