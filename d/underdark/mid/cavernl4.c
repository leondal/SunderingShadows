#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"cavernk4",
     "southwest":MID"cavernk3",
     "south":MID"cavernl3",
     "north":MID"cavernl5",
     "east":MID"cavernm4",
     "southeast":MID"cavernm3",
     "northeast":MID"cavernm5",
   ]));
}
