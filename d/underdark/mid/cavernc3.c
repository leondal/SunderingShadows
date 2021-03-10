#include <std.h>
#include "../defs.h"
inherit INH+"cavern2";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"%^CYAN%^  To the west, a small "
"tunnel entrance yawns open from the wall, leading further into %^BOLD%^%^BLACK%^darkness%^RESET%^%^CYAN%^."
"%^RESET%^\n");
   add_item(({"tunnel","western wall","entrance"}),"%^CYAN%^To the west, the cavern wall opens into a small "
"tunnel, leading from ground level upward into %^BOLD%^%^BLACK%^darkness%^RESET%^%^CYAN%^.%^RESET%^");
   set_exits(([
     "west":MID"cavernb3",
     "northwest":MID"cavernb4",
     "southwest":MID"cavernb2",
     "north":MID"cavernc4",
     "south":MID"cavernc2",
     "east":MID"cavernd3",
     "northeast":MID"cavernd4",
     "southeast":MID"cavernd2",
   ]));
}
