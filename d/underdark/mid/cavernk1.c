#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"cavernj1",
     "southeast":MID"cavernj0",
     "northwest":MID"cavernj2",
     "south":MID"cavernk0",
     "north":MID"cavernk2",
     "east":MID"cavernl1",
     "southeast":MID"cavernl0",
     "northeast":MID"cavernl2",
   ]));
}
