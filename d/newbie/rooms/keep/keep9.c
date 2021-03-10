#include <std.h>
#include "../inherit/keep.h"
inherit INH+"keephall";

void create(){ 
   ::create();
   set_long(::query_long() +"  The hallway leads off from this point to the "
"north and south.\n");
   set_exits(([
     "north" : ROOMS"keep10",
     "south" : ROOMS"keep8",
     "west" : ROOMS"halfogre1",
   ]));
   set_door("door",ROOMS"halfogre1","west",0);
   set_door_description("door","%^ORANGE%^This door is aged and loose on its "
"hinges.  It has what may once have been carved patterns on it, but these are "
"long worn away and impossible to make out.%^RESET%^");
}
