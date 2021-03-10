#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   add_item(({"tunnel","western wall","entrance"}),"%^CYAN%^Further to the north, a massive tunnel entrance "
"can be seen, leading northwards into %^BOLD%^%^BLACK%^darkness%^RESET%^%^CYAN%^.%^RESET%^");
   set_exits(([
     "west":MID"caverno6",
     "southwest":MID"caverno5",
     "northwest":MID"caverno7",
     "south":MID"cavernp5",
     "north":MID"cavernp7",
     "east":MID"cavernq6",
   ]));
}
