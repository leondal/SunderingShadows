#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"cavernj3",
     "northwest":MID"cavernj4",
     "southwest":MID"cavernj2",
     "north":MID"cavernk4",
     "south":MID"cavernk2",
     "east":MID"cavernl3",
     "northeast":MID"cavernl4",
     "southeast":MID"cavernl2",
   ]));
}
