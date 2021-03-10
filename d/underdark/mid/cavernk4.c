#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"cavernj4",
     "southwest":MID"cavernj3",
     "south":MID"cavernk3",
     "east":MID"cavernl4",
     "southeast":MID"cavernl3",
     "northeast":MID"cavernl5",
   ]));
}
