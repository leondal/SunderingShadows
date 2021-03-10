#include <std.h>
#include "../defs.h"
inherit INH+"bridge";

void create(){ 
   ::create();
   set_long("%^MAGENTA%^A bridge crossing the Wailing Chasm%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "southwest":MID"bridge04",
     "northeast":MID"bridge06",
   ]));
   set_pre_exit_functions(({"southwest","northeast"}),({"GoThroughDoor","GoThroughDoor"}));
}
