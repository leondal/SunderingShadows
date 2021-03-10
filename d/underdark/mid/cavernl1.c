#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"cavernk1",
     "southeast":MID"cavernk0",
     "southwest":MID"cavernk0",
     "northwest":MID"cavernk2",
     "south":MID"cavernl0",
     "north":MID"cavernl2",
     "east":MID"cavernm1",
     "southeast":MID"cavernm0",
     "northeast":MID"cavernm2",
   ]));
}
