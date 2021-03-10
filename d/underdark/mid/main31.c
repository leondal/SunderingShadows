#include <std.h>
#include "../defs.h"
inherit INH+"main";

void create(){ 
   ::create();
   set_long("%^BLUE%^A broad underground tunnel%^RESET%^\n"+ ::query_long() +
"%^ORANGE%^  A few more steps east, the tunnel opens up onto the empty air of "
"a %^BOLD%^%^BLACK%^vast chasm%^RESET%^%^ORANGE%^, from which a narrow path "
"leads around and out of sight to the south.%^RESET%^\n");
   set_exits(([
     "east":MID"chasm01",
     "west":MID"main30",
   ]));
}
