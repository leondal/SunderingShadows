#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"cavernc3",
     "northwest":MID"cavernc4",
     "southwest":MID"cavernc2",
     "north":MID"cavernd4",
     "south":MID"cavernd2",
     "east":MID"caverne3",
     "northeast":MID"caverne4",
     "southeast":MID"caverne2",
   ]));
}
