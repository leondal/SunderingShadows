#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"cavernc2",
     "southwest":MID"cavernc1",
     "northwest":MID"cavernc3",
     "north":MID"cavernd3",
     "south":MID"cavernd1",
     "east":MID"caverne2",
     "southeast":MID"caverne1",
     "northeast":MID"caverne3",
   ]));
}
