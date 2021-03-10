#include <std.h>
#include "../defs.h"
inherit INH+"cavern2";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"cavernn3",
     "northwest":MID"cavernn4",
     "southwest":MID"cavernn2",
     "north":MID"caverno4",
     "south":MID"caverno2",
     "east":MID"cavernp3",
     "northeast":MID"cavernp4",
     "southeast":MID"cavernp2",
   ]));
}
