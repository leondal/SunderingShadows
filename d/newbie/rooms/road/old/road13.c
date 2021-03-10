//road13.c

#include <std.h>
#include "../../newbie.h"

inherit "/d/newbie/rooms/inherit/roadrats";

void create(){ 
   ::create();
   set_property("light",2);
   set_property("no teleport",1);
   set_terrain(SCRUB_LANDS);
   set_travel(PAVED_ROAD);

   set_short("A wide gravel trail");
   set_long(
@JAVAMAKER
You are on a wide trail passing through some small hills.
You can see a forest off in the distance to the west. 
JAVAMAKER
   );

   set_smell("default","You smell the fresh air of the open land.");
   set_listen("default","You hear the sound of the wind rushing across the open land.");
   set_items(([
   ]));

   set_exits(([
      "north":ROAD"road12",
      "southwest":ROAD"road14",
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







