#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"cavernl2",
     "southwest":MID"cavernl1",
     "northwest":MID"cavernl3",
     "north":MID"cavernm3",
     "south":MID"cavernm1",
     "east":MID"cavernn2",
     "southeast":MID"cavernn1",
     "northeast":MID"cavernn3",
   ]));
}
