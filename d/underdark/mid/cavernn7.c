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
     "south":MID"cavernn6",
     "east":MID"caverno7",
     "southeast":MID"caverno6",
     "northeast":MID"caverno8",
   ]));
}
