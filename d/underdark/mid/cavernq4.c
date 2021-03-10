#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"cavernp4",
     "southwest":MID"cavernp3",
     "northwest":MID"cavernp5",
     "south":MID"cavernq3",
   ]));
}
