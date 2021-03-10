#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"%^CYAN%^  To the west, a small "
"tunnel entrance yawns open from the wall, leading further into %^BOLD%^%^BLACK%^darkness%^RESET%^%^CYAN%^."
"%^RESET%^\n");
   add_item(({"tunnel","western wall","entrance"}),"%^CYAN%^To the west, the cavern wall opens into a small "
"tunnel, leading from ground level upward into %^BOLD%^%^BLACK%^darkness%^RESET%^%^CYAN%^.%^RESET%^");
   set_exits(([
     "west":MID"cavernb2",
     "northwest":MID"cavernb3",
     "north":MID"cavernc3",
     "south":MID"cavernc1",
     "east":MID"cavernd2",
     "southeast":MID"cavernd1",
     "northeast":MID"cavernd3",
   ]));
}
