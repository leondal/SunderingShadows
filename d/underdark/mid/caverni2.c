#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"cavernh2",
     "southwest":MID"cavernh1",
     "northwest":MID"cavernh3",
     "north":MID"caverni3",
     "south":MID"caverni1",
     "east":MID"cavernj2",
     "southeast":MID"cavernj1",
     "northeast":MID"cavernj3",
   ]));
}
