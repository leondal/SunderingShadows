#include <std.h>
#include "../inherit/keep.h"
inherit INH+"keephall2";

void create(){ 
   ::create();
   set_long(::query_long() +"  The hallway continues to the north and seems to "
"have fallen in on itself further south.  A small, shabby %^ORANGE%^door "
"%^RESET%^set into the wall probably leads to another storage room.\n");
   set_exits(([
     "north" : ROOMS"keep18",
     "south" : ROOMS"keep20",
     "west" : ROOMS"storage3",
   ]));
   set_door("door",ROOMS"storage3","west",0);
   set_door_description("door","%^ORANGE%^A simple wooden door, scratched and "
"grimy from years of abuse, but still intact.  Its hinges are rusted and "
"probably very stiff.%^RESET%^");
   set_string("door","open","The door sheds dust as it creaks open.");
   set_string("door","close","The door creaks shut.");
}
