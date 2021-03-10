#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"cavernm1",
     "southwest":MID"cavernm0",
     "northwest":MID"cavernm2",
     "north":MID"cavernn2",
     "east":MID"caverno1",
     "northeast":MID"caverno2",
   ]));
}
