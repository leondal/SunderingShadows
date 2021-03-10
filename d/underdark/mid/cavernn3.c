#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"cavernm3",
     "northwest":MID"cavernm4",
     "southwest":MID"cavernm2",
     "north":MID"cavernn4",
     "south":MID"cavernn2",
     "east":MID"caverno3",
     "northeast":MID"caverno4",
     "southeast":MID"caverno2",
   ]));
}
