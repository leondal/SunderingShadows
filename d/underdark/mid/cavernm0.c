#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"cavernl0",
     "northwest":MID"cavernl1",
     "north":MID"cavernm1",
     "northeast":MID"cavernn1",
   ]));
}
