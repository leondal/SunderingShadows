#include <std.h>
#include "../inherit/keep.h"
inherit INH+"keephall";

void create(){ 
   ::create();
   set_long(::query_long() +"  The hallway leads off from this point to the "
"north and south, where you can see doors along the corridor.\n");
   set_exits(([
     "north" : ROOMS"keep9",
     "south" : ROOMS"keep7",
   ]));
}
