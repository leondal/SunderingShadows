#include <std.h>
#include "../inherit/keep.h"
inherit INH+"keephall2";

void create(){ 
   ::create();
   set_long(::query_long() +"  Crumbling walls to the west offer a way out of "
"the building.\n");
   set_exits(([
     "west" : ROOMS"keep2",
     "east" : ROOMS"keep4",
   ]));
}
