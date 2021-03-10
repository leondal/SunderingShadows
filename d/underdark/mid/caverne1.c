#include <std.h>
#include "../defs.h"
inherit INH+"cavern2";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"cavernd1",
     "northwest":MID"cavernd2",
     "north":MID"caverne2",
     "east":MID"cavernf1",
     "northeast":MID"cavernf2",
   ]));
}
