#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"caverne4",
     "southwest":MID"caverne3",
     "south":MID"cavernf3",
     "east":MID"caverng4",
     "southeast":MID"caverng3",
   ]));
}
