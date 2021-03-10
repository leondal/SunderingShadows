#include <std.h>
#include "../inherit/keep.h"
inherit INH+"keephall2";

void create(){ 
   ::create();
   set_long(::query_long() +"  The hallway continues to the north and south, "
"while a small, creaky %^ORANGE%^door %^RESET%^set into the wall probably leads "
"to another storage room.\n");
   set_exits(([
     "north" : ROOMS"keep17",
     "south" : ROOMS"keep19",
     "east" : ROOMS"storage2",
   ]));
   set_door("door",ROOMS"storage2","east",0);
   set_door_description("door","%^ORANGE%^A simple wooden door, scratched and "
"grimy from years of abuse, but still intact.  Its hinges are rusted and "
"probably very stiff.%^RESET%^");
   set_string("door","open","The door opens with a loud creak.");
   set_string("door","close","The door creaks shut.");
}
