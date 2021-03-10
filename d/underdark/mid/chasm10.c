#include <std.h>
#include "../defs.h"
inherit INH+"chasm";

void create(){ 
   ::create();
   set_long("%^MAGENTA%^Within the Wailing Chasm%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"chasm09",
     "southeast":MID"chasm11",
   ]));
   set_pre_exit_functions(({"west","southeast"}),({"GoThroughDoor","GoThroughDoor"}));
}
