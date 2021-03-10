//road1.c

#include <std.h>
#include "../../newbie.h"

inherit ROOM;

void create(){ 
   ::create();
   set_property("light",2);
   set_property("no teleport",1);
   set_terrain(SCRUB_LANDS);
   set_travel(PAVED_ROAD);
   set_short("A trail near the city");
   set_long(
@JAVAMAKER
You are on a wide trail leading east and west, between the 
city to the west and some small hills to the east. Open
land stretches out to the north and you can see a forest
off to the south.
JAVAMAKER
   );

   set_smell("default","You smell the fresh air of the open land.");
   set_listen("default","You hear the sound of the wind rushing across the open land.");
   set_items(([
   ]));

   set_exits(([
      "east":ROAD"road2",
      "west":MAINTOWN"eroad1",
   ]));

   set_invis_exits(({}));
   set_trap_functions(({}),({}),({}));
   set_pre_exit_functions(({}),({}));
   set_post_exit_functions(({}),({}));
}


void reset(){
   ::reset();

}

void init(){
   ::init();

}
