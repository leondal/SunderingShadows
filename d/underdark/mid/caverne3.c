#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"\n");
   set_exits(([
     "west":MID"cavernd3",
     "northwest":MID"cavernd4",
     "southwest":MID"cavernd2",
     "north":MID"caverne4",
     "south":MID"caverne2",
     "east":MID"cavernf3",
     "northeast":MID"cavernf4",
     "southeast":MID"cavernf2",
   ]));
}
