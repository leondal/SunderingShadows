#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"cavernd2",
     "southwest":MID"cavernd1",
     "northwest":MID"cavernd3",
     "north":MID"caverne3",
     "south":MID"caverne1",
     "east":MID"cavernf2",
     "southeast":MID"cavernf1",
     "northeast":MID"cavernf3",
   ]));
}
