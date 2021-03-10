#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"cavernn1",
     "northwest":MID"cavernn2",
     "north":MID"caverno2",
     "northeast":MID"cavernp2",
   ]));
}
