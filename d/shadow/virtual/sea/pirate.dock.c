//dock.c

#include <std.h>
#include "/d/islands/pirates/piratedefs.h"

inherit DOCK;

void create(){ 
   ::create();
   set_property("light",2);
   set_property("no teleport",1);
  set_terrain(BARREN);
  set_travel(DECAYED_FLOOR);

   set_short(
@JAVAMAKER
Pirate's Cove Docks
JAVAMAKER
   );

   set_long(
@JAVAMAKER
%^BOLD%^Southern Docks%^RESET%^
You have found an open dock here that isn't being used.
The water swells along the docks.  And you can see the ocean
spead out to the horizon. The north are the docks used
by the pirate ships.  

JAVAMAKER
   );

   set_smell("default","You smell the fresh ocean air.");
   set_listen("default","You hear water rushing under the docks.");
   set_items(([
      "ocean":"It looks rough, and is vast.",
      "docks":"These are old and rough hewn and worn but they seem sturdy enough.",
   ]));

   set_exits(([
      "north":COVE"dock4",
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







