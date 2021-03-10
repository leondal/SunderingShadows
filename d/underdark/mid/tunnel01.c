#include <std.h>
#include "../defs.h"
inherit INH+"tunnel";

void create(){ 
   ::create();
   set_name("The opening to a dark tunnel");
   set_short("%^BOLD%^%^BLACK%^The opening to a dark tunnel%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^The opening to a dark tunnel%^RESET%^\n"+ ::query_long() +"%^BLUE%^  Just above "
"you to the west, the tunnel opens up onto the empty air of a sheer chasm wall, from which leads a narrow "
"bridge of %^WHITE%^stone%^BLUE%^.%^RESET%^\n");
   set_exits(([
     "bridge":MID"bridge11",
     "east":MID"tunnel02",
   ]));
}
