#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"caverng3",
     "northwest":MID"caverng4",
     "southwest":MID"caverng2",
     "north":MID"cavernh4",
     "south":MID"cavernh2",
     "east":MID"caverni3",
     "northeast":MID"caverni4",
     "southeast":MID"caverni2",
   ]));
}
