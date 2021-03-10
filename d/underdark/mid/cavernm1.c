#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"cavernl1",
     "southwest":MID"cavernl0",
     "northwest":MID"cavernl2",
     "south":MID"cavernm0",
     "north":MID"cavernm2",
     "east":MID"cavernn1",
     "northeast":MID"cavernn2",
   ]));
}
