#include <std.h>
#include "../defs.h"
inherit INH+"bridge";

void create(){ 
   ::create();
   set_long("%^MAGENTA%^A bridge crossing the Wailing Chasm%^RESET%^\n"+ ::query_long() +"%^BLUE%^  Just to "
"the east, the bridge meets the %^WHITE%^dull stone wall %^BLUE%^of the chasm itself, at the mouth of a "
"%^BOLD%^%^BLACK%^dark tunnel%^RESET%^%^BLUE%^.%^RESET%^\n");
   set_exits(([
     "southwest":MID"bridge08",
     "northeast":MID"bridge10",
   ]));
   set_pre_exit_functions(({"southwest","northeast"}),({"GoThroughDoor","GoThroughDoor"}));
}
