#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"caverno3",
     "northwest":MID"caverno4",
     "southwest":MID"caverno2",
     "north":MID"cavernp4",
     "south":MID"cavernp2",
     "east":MID"cavernq3",
     "northeast":MID"cavernq4",
     "southeast":MID"cavernq2",
   ]));
}
