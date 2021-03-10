#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"cavernf2",
     "southwest":MID"cavernf1",
     "northwest":MID"cavernf3",
     "north":MID"caverng3",
     "south":MID"caverng1",
     "east":MID"cavernh2",
     "southeast":MID"cavernh1",
     "northeast":MID"cavernh3",
   ]));
}
