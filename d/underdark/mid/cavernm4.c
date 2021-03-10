#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"cavernl4",
     "southwest":MID"cavernl3",
     "northwest":MID"cavernl5",
     "south":MID"cavernm3",
     "north":MID"cavernm5",
     "east":MID"cavernn4",
     "southeast":MID"cavernn3",
     "northeast":MID"cavernn5",
   ]));
}
