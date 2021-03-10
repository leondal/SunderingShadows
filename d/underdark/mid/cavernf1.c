#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"caverne1",
     "northwest":MID"caverne2",
     "north":MID"cavernf2",
     "east":MID"caverng1",
     "northeast":MID"caverng2",
   ]));
}
