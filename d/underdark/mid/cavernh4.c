#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"caverng4",
     "southwest":MID"caverng3",
     "south":MID"cavernh3",
     "east":MID"caverni4",
     "southeast":MID"caverni3",
   ]));
}
