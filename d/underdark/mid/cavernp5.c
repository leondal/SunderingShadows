#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"caverno5",
     "southwest":MID"caverno4",
     "northwest":MID"caverno6",
     "south":MID"cavernp4",
     "north":MID"cavernp6",
     "southeast":MID"cavernq4",
     "northeast":MID"cavernq6",
   ]));
}
