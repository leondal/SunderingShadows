//test_room
#include <std.h>
#include "../seneca.h"

inherit VIENTO;

void create(){
   ::create();
   set_exits(([
      "west" : ROOMS"test_room"
   ]));
   set_post_exit_functions(({"west"}),({"GoThroughDoor"}));
}

int GoThroughDoor(){
   tell_object(TP,"You just left the room.");
   tell_object(find_player("circe"),""+TPQCN+" just left test_room2.");
   return ::GoThroughDoor();
}