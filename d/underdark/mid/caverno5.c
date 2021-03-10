#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"cavernn5",
     "southwest":MID"cavernn4",
     "northwest":MID"cavernn6",
     "south":MID"caverno4",
     "north":MID"caverno6",
     "east":MID"cavernp5",
     "southeast":MID"cavernp4",
     "northeast":MID"cavernp6",
   ]));
}
