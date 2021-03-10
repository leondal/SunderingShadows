#include <std.h>
#include "../defs.h"
inherit INH+"bridge";

void create(){ 
   ::create();
   set_long("%^MAGENTA%^A bridge crossing the Wailing Chasm%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "southwest":MID"bridge07",
     "northeast":MID"bridge09",
   ]));
   set_pre_exit_functions(({"southwest","northeast"}),({"GoThroughDoor","GoThroughDoor"}));
}
