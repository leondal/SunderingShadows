#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "northwest":MID"cavernh1",
     "north":MID"caverni1",
     "east":MID"cavernj0",
     "northeast":MID"cavernj1",
   ]));
}
