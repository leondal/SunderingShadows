#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   add_item(({"tunnel","western wall","entrance"}),"%^CYAN%^Further to the north, a massive tunnel entrance "
"can be seen, leading northwards into %^BOLD%^%^BLACK%^darkness%^RESET%^%^CYAN%^.%^RESET%^");
   set_exits(([
     "southwest":MID"cavernm5",
     "south":MID"cavernn5",
     "north":MID"cavernn7",
     "east":MID"caverno6",
     "southeast":MID"caverno5",
     "northeast":MID"caverno7",
   ]));
}
