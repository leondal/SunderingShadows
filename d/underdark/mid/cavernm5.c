#include <std.h>
#include "../defs.h"
inherit INH+"cavern2";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"cavernl5",
     "southwest":MID"cavernl4",
     "south":MID"cavernm4",
     "east":MID"cavernn5",
     "southeast":MID"cavernn4",
     "northeast":MID"cavernn6",
   ]));
}
