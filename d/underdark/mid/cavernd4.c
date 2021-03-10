#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"cavernc4",
     "southwest":MID"cavernc3",
     "south":MID"cavernd3",
     "east":MID"caverne4",
     "southeast":MID"caverne3",
   ]));
}
