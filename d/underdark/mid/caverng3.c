#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"cavernf3",
     "northwest":MID"cavernf4",
     "southwest":MID"cavernf2",
     "north":MID"caverng4",
     "south":MID"caverng2",
     "east":MID"cavernh3",
     "northeast":MID"cavernh4",
     "southeast":MID"cavernh2",
   ]));
}
