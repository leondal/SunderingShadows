//cave30.c
#include <std.h>
#include "echoes.h"

inherit OGRES;

void create(){
    ::create();
    set_exits(([
        "east" : ROOMS"cave31",
        "north" : ROOMS"cave29",
         "west" : "/d/shadow/room/deep_echos/enter"
   	]));
   set_pre_exit_functions(({"west"}),({"GoThroughDoor"}));
}

int GoThroughDoor()
{
   if(TP->query_lowest_level() < 12) {
   tell_object(TP,"You think twice about heading deeper into the cave.");
      return 0;
   }
   return 1;
}
/*
void reset() {
  ::reset();
  if(!present("ogre")) {
    new(MOBS"ogre")->move(TO);
    new(MOBS"ogre")->move(TO);
  }
}
*/
