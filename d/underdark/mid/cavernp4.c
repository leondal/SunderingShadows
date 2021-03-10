#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"caverno4",
     "southwest":MID"caverno3",
     "northwest":MID"caverno5",
     "south":MID"cavernp3",
     "north":MID"cavernp5",
     "east":MID"cavernq4",
     "southeast":MID"cavernq3",
   ]));
}
