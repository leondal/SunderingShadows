#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"cavernj0",
     "northwest":MID"cavernj1",
     "north":MID"cavernk1",
     "east":MID"cavernl0",
     "northeast":MID"cavernl1",
   ]));
}
