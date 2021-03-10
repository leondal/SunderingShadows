#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"cavernn4",
     "southwest":MID"cavernn3",
     "northwest":MID"cavernn5",
     "south":MID"caverno3",
     "north":MID"caverno5",
     "east":MID"cavernp4",
     "southeast":MID"cavernp3",
     "northeast":MID"cavernp5",
   ]));
}
