#include <std.h>
#include "../inherit/keep.h"
inherit INH+"keepupper";

void create(){ 
   ::create();
   set_long(::query_long() +"  The hall extends further to the south and west.\n");
   set_exits(([
     "west" : ROOMS"floor1",
     "south" : ROOMS"floor4",
   ]));
}
