#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"caverni1",
     "southeast":MID"caverni0",
     "northwest":MID"caverni2",
     "south":MID"cavernj0",
     "north":MID"cavernj2",
     "east":MID"cavernk1",
     "southeast":MID"cavernk0",
     "northeast":MID"cavernk2",
   ]));
}
