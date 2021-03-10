#include <std.h>
#include "../defs.h"
inherit INH+"chasm";

void create(){ 
   ::create();
   set_long("%^MAGENTA%^Within the Wailing Chasm%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "north":MID"chasm18",
     "southeast":MID"chasm20",
   ]));
   set_pre_exit_functions(({"north","southeast"}),({"GoThroughDoor","GoThroughDoor"}));
}
