#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"caverni4",
     "southwest":MID"caverni3",
     "south":MID"cavernj3",
     "east":MID"cavernk4",
     "southeast":MID"cavernk3",
   ]));
}
