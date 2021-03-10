#include <std.h>
#include "../defs.h"
inherit INH+"main";

void create(){ 
   ::create();
   set_long("%^BLUE%^A broad underground tunnel%^RESET%^\n"+ ::query_long() +
"%^ORANGE%^  Directly in front of you rises the oppressive form of a %^BOLD%^"
"%^BLACK%^massive black gate%^RESET%^%^ORANGE%^, obstructing any further "
"travel to the west.  It is firmly closed, leaving you only to guess at what "
"lies behind it.%^RESET%^\n");
   set_exits(([
     "east":MID"main02",
   ]));
}
