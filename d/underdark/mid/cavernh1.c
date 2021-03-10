#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"caverng1",
     "northwest":MID"caverng2",
     "north":MID"cavernh2",
     "east":MID"caverni1",
     "southeast":MID"caverni0",
     "northeast":MID"caverni2",
   ]));
}
