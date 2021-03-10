#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"caverne2",
     "southwest":MID"caverne1",
     "northwest":MID"caverne3",
     "north":MID"cavernf3",
     "south":MID"cavernf1",
     "east":MID"caverng2",
     "southeast":MID"caverng1",
     "northeast":MID"caverng3",
   ]));
}
