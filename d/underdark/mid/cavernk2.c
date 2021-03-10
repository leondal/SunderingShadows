#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"cavernj2",
     "southwest":MID"cavernj1",
     "northwest":MID"cavernj3",
     "north":MID"cavernk3",
     "south":MID"cavernk1",
     "east":MID"cavernl2",
     "southeast":MID"cavernl1",
     "northeast":MID"cavernl3",
   ]));
}
