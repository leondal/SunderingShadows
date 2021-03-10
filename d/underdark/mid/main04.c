#include <std.h>
#include "../defs.h"
inherit INH+"main";

void create(){ 
   ::create();
   set_long("%^BLUE%^A broad underground tunnel%^RESET%^\n"+ ::query_long() +
"%^ORANGE%^  A short distance to the west, you can see the shape of a vast "
"gate that obstructs further travel along the roadway.%^RESET%^\n");
   set_exits(([
     "east":MID"main05",
     "west":MID"main03",
   ]));
}
