//market4.c

#include <std.h>
#include "../tharis.h"

inherit "/d/tharis/Tharis/market";

void create(){ 
   ::create();
   set_property("light",2);

   set_short(
@JAVAMAKER
The center of the Tharis market place
JAVAMAKER
   );

   set_long(
@JAVAMAKER
%^BOLD%^%^BLUE%^The center of the Tharis market placet%^RESET%^
Here the market place intersects with the east/west road. The movement here
slows to a crawl as the citizens and merchants and laborers
clog the streets. In all directions the crowds swarm and the 
merchants shout.
JAVAMAKER
   );

   set_smell("default","You smell the food from the vendors and the people around you.");
   set_listen("default","The crowd is loud.");
   set_items(([
      "crowd":"This is a busy busy place. Obvisouly a great haven for thieves.",
   ]));

   set_exits(([
      "southwest":ROOMS"market5",
      "south":ROOMS"market6",
      "west":ROOMS"market3",
      "north":ROOMS"market2",
      "east":ROOMS"estreet1",
      "northwest":ROOMS"market1",
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







