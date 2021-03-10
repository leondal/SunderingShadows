#include <std.h>
#include "../defs.h"
inherit INH+"cavern2";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"caverni2",
     "southwest":MID"caverni1",
     "northwest":MID"caverni3",
     "north":MID"cavernj3",
     "south":MID"cavernj1",
     "east":MID"cavernk2",
     "southeast":MID"cavernk1",
     "northeast":MID"cavernk3",
   ]));
}
