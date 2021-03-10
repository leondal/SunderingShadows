//road12.c

#include <std.h>
#include "../../newbie.h"

inherit ROOM;

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
You can see a forest off in the distance to the west. You 
can see some small footprints on the ground, leading
into the hills.
JAVAMAKER
   );

   set_smell("default","You smell the fresh air of the open land.");
   set_listen("default","You hear the sound of the wind rushing across the open land.");
   set_items(([
   ]));

   set_exits(([
      "north":ROAD"road11",
      "south":ROAD"road13",
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







