#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"cavernl3",
     "northwest":MID"cavernl4",
     "southwest":MID"cavernl2",
     "north":MID"cavernm4",
     "south":MID"cavernm2",
     "east":MID"cavernn3",
     "northeast":MID"cavernn4",
     "southeast":MID"cavernn2",
   ]));
}
