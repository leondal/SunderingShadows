#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"cavernh1",
     "northwest":MID"cavernh2",
     "south":MID"caverni0",
     "north":MID"caverni2",
     "east":MID"cavernj1",
     "southeast":MID"cavernj0",
     "northeast":MID"cavernj2",
   ]));
}
