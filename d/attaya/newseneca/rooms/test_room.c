//test_room
#include <std.h>
#include "../seneca.h"

inherit VIENTO;

void create(){
   ::create();
   set_exits(([
      "east" : ROOMS"test_room2"
   ]));
   set_pre_exit_functions(({"east"}),({"GoThroughDoor"}));
}

int GoThroughDoor(){
   tell_object(TP,"You just left the room.");
   tell_object(find_player("circe"),""+TPQCN+" just left test_room.");
   return ::GoThroughDoor();
}