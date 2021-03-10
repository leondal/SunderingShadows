#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"caverni3",
     "northwest":MID"caverni4",
     "southwest":MID"caverni2",
     "north":MID"cavernj4",
     "south":MID"cavernj2",
     "east":MID"cavernk3",
     "northeast":MID"cavernk4",
     "southeast":MID"cavernk2",
   ]));
}
