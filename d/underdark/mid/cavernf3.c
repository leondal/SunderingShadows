#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"caverne3",
     "northwest":MID"caverne4",
     "southwest":MID"caverne2",
     "north":MID"cavernf4",
     "south":MID"cavernf2",
     "east":MID"caverng3",
     "northeast":MID"caverng4",
     "southeast":MID"caverng2",
   ]));
}
