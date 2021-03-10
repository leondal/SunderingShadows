#include <std.h>
#include "../defs.h"
inherit INH+"chasm";

void create(){ 
   ::create();
   set_long("%^MAGENTA%^Within the Wailing Chasm%^RESET%^\n"+ ::query_long() +"%^BLUE%^  A little to the "
"northwest, the path meets with a large tunnel that leads into the chasm wall.%^RESET%^\n");
   add_item(({"tunnel","road"}),"%^BLUE%^To the northwest, the path meets with a %^WHITE%^large tunnel "
"%^BLUE%^in the wall of the cavern.%^RESET%^");
   set_exits(([
     "northwest":MID"chasm02",
     "southeast":MID"chasm04",
   ]));
   set_pre_exit_functions(({"northwest","southeast"}),({"GoThroughDoor","GoThroughDoor"}));
}
