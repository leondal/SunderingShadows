#include <std.h>
#include "../inherit/keep.h"
inherit INH+"keepupper";

void create(){ 
   ::create();
   set_long(::query_long() +"  The hall extends further to the north and west, "
"while a doorway leads into a private room to the east.\n");
   set_exits(([
     "west" : ROOMS"floor3",
     "north" : ROOMS"floor2",
     "east" : ROOMS"floor5",
   ]));
   set_door("door",ROOMS"floor5","east",0);
   set_door_description("door","%^ORANGE%^This door is solid and reinforced "
"with metal bars.  It is aged and worn, but still standing.%^RESET%^");
}
