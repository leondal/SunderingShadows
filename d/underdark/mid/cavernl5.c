#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "southwest":MID"cavernk4",
     "south":MID"cavernl4",
     "east":MID"cavernm5",
     "southeast":MID"cavernm4",
   ]));
}
