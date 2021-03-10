#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"cavernh4",
     "southwest":MID"cavernh3",
     "south":MID"caverni3",
     "east":MID"cavernj4",
     "southeast":MID"cavernj3",
   ]));
}
