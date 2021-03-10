#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"cavernk3",
     "northwest":MID"cavernk4",
     "southwest":MID"cavernk2",
     "north":MID"cavernl4",
     "south":MID"cavernl2",
     "east":MID"cavernm3",
     "northeast":MID"cavernm4",
     "southeast":MID"cavernm2",
   ]));
}
