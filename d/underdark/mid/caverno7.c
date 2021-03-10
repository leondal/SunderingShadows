#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"%^CYAN%^  Further to the north, a "
"%^BOLD%^%^BLACK%^small dark hole %^RESET%^%^CYAN%^can be seen in the wall.%^RESET%^\n");
   add_item(({"tunnel","western wall","entrance"}),"%^CYAN%^Further to the north, a massive tunnel entrance "
"can be seen, leading northwards into %^BOLD%^%^BLACK%^darkness%^RESET%^%^CYAN%^.%^RESET%^");
   set_exits(([
     "west":MID"cavernn7",
     "southwest":MID"cavernn6",
     "south":MID"caverno6",
     "north":MID"caverno8",
     "east":MID"cavernp7",
     "southeast":MID"cavernp6",
   ]));
}
