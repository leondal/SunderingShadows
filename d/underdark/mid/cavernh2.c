#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"caverng2",
     "southwest":MID"caverng1",
     "northwest":MID"caverng3",
     "north":MID"cavernh3",
     "south":MID"cavernh1",
     "east":MID"caverni2",
     "southeast":MID"caverni1",
     "northeast":MID"caverni3",
   ]));
}
