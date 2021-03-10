#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"cavernm5",
     "southwest":MID"cavernm4",
     "south":MID"cavernn4",
     "north":MID"cavernn6",
     "east":MID"caverno5",
     "southeast":MID"caverno4",
     "northeast":MID"caverno6",
   ]));
}
