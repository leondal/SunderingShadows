#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"cavernc1",
     "northwest":MID"cavernc2",
     "north":MID"cavernd2",
     "east":MID"caverne1",
     "northeast":MID"caverne2",
   ]));
}
