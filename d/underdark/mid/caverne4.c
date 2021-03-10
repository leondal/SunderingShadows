#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"cavernd4",
     "southwest":MID"cavernd3",
     "south":MID"caverne3",
     "east":MID"cavernf4",
     "southeast":MID"cavernf3",
   ]));
}
