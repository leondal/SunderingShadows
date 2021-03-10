#include <std.h>
#include "../defs.h"
inherit INH+"cavern2";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"cavernk0",
     "northwest":MID"cavernk1",
     "north":MID"cavernl1",
     "east":MID"cavernm0",
     "northeast":MID"cavernm1",
   ]));
}
