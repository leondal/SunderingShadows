#include <std.h>
#include "../inherit/keep.h"
inherit INH+"keepupper";

void create(){ 
   ::create();
   set_long(::query_long() +"  The hall extends further to the north and east.\n");
   set_exits(([
     "east" : ROOMS"floor4",
     "north" : ROOMS"floor1",
   ]));
}
