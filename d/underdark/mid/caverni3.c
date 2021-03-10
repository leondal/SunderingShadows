#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"cavernh3",
     "northwest":MID"cavernh4",
     "southwest":MID"cavernh2",
     "north":MID"caverni4",
     "south":MID"caverni2",
     "east":MID"cavernj3",
     "northeast":MID"cavernj4",
     "southeast":MID"cavernj2",
   ]));
}
