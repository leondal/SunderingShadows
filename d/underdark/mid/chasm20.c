#include <std.h>
#include "../defs.h"
inherit INH+"chasm";

void create(){ 
   ::create();
   set_long("%^MAGENTA%^Within the Wailing Chasm%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "northwest":MID"chasm19",
     "southeast":MID"chasm21",
   ]));
   set_pre_exit_functions(({"northwest","southeast"}),({"GoThroughDoor","GoThroughDoor"}));
}
