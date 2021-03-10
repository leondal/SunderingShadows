#include <std.h>
#include "../defs.h"
inherit INH+"chasm";

void create(){ 
   ::create();
   set_name("Entering the Wailing Chasm");
   set_short("%^MAGENTA%^Entering the Wailing Chasm%^RESET%^");
   set_long("%^MAGENTA%^Entering the Wailing Chasm%^RESET%^\n"+ ::query_long() +"%^BLUE%^  The path meets with "
"a large tunnel here, inset with a road that leads back to the west.%^RESET%^\n");
   add_item(({"tunnel","road"}),"%^BLUE%^The path meets here at a %^WHITE%^large tunnel %^BLUE%^in the wall of "
"the cavern.  What must serve for a fairly well-used road leads back down the tunnel to the west.%^RESET%^");
   set_exits(([
     "west":MID"main31",
     "southeast":MID"chasm02",
   ]));
   set_pre_exit_functions(({"southeast"}),({"GoThroughDoor"}));
}
