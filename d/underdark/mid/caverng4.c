#include <std.h>
#include "../defs.h"
inherit INH+"cavern2";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"cavernf4",
     "southwest":MID"cavernf3",
     "south":MID"caverng3",
     "east":MID"cavernh4",
     "southeast":MID"cavernh3",
   ]));
}
