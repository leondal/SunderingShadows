#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"cavernm4",
     "southwest":MID"cavernm3",
     "northwest":MID"cavernm5",
     "south":MID"cavernn3",
     "north":MID"cavernn5",
     "east":MID"caverno4",
     "southeast":MID"caverno3",
     "northeast":MID"caverno5",
   ]));
}
