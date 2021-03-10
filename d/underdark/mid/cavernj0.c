#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"caverni0",
     "northwest":MID"caverni1",
     "north":MID"cavernj1",
     "east":MID"cavernk0",
     "northeast":MID"cavernk1",
   ]));
}
