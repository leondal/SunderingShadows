#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"cavernn2",
     "southwest":MID"cavernn1",
     "northwest":MID"cavernn3",
     "south":MID"caverno1",
     "north":MID"caverno3",
     "east":MID"cavernp2",
     "northeast":MID"cavernp3",
   ]));
}
