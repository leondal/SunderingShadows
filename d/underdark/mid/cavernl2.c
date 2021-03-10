#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"cavernk2",
     "southwest":MID"cavernk1",
     "northwest":MID"cavernk3",
     "north":MID"cavernl3",
     "south":MID"cavernl1",
     "east":MID"cavernm2",
     "southeast":MID"cavernm1",
     "northeast":MID"cavernm3",
   ]));
}
