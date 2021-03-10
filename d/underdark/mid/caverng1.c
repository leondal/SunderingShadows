#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"cavernf1",
     "northwest":MID"cavernf2",
     "north":MID"caverng2",
     "east":MID"cavernh1",
     "northeast":MID"cavernh2",
   ]));
}
