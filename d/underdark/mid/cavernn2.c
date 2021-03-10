#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"cavernm2",
     "southwest":MID"cavernm1",
     "northwest":MID"cavernm3",
     "north":MID"cavernn3",
     "south":MID"cavernn1",
     "east":MID"caverno2",
     "southeast":MID"caverno1",
     "northeast":MID"caverno3",
   ]));
}
