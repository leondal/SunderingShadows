#include <std.h>
#include "../defs.h"
inherit INH+"main";

void create(){ 
   ::create();
   set_long("%^BLUE%^A broad underground tunnel%^RESET%^\n"+ ::query_long() +
"%^ORANGE%^  A short way east, the tunnel opens up onto the empty air of "
"a %^BOLD%^%^BLACK%^vast chasm%^RESET%^%^ORANGE%^.%^RESET%^\n");
   set_exits(([
     "east":MID"main31",
     "west":MID"main29",
   ]));
}
