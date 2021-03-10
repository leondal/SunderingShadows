//workers added by Circe 10/2/05 to build the Tharis Mage Hub submitted by
//Sevotharte.  They will be removed when the hub goes in.
//market6.c

#include <std.h>
#include "../tharis.h"

inherit "/d/tharis/Tharis/market";

void create(){ 
   ::create();
   set_property("light",2);

   set_short(
@JAVAMAKER
The market before the Palace
JAVAMAKER
   );

   set_long(
@JAVAMAKER
%^BOLD%^%^BLUE%^The market before the palace%^RESET%^
Here the market place run up against the walls of the palace
the iron gate of the palace stands closed to the south. The high
wall of the palace diagonally to the southeast. The crowd bustles
with commercialism with equal enthusiasm here as it does else
where.
JAVAMAKER
   );

   set_smell("default","You smell the food from the vendors and the people around you.");
   set_listen("default","The crowd is loud.");
   set_items(([
      "crowd":"This is a busy busy place. Obviously a great haven for thieves.",
      "walls":"These steep walls are made of massive stone and have long cracks and deep ruts. These you notice weaken the strength of the walls. This is a sharp contrast to the outer walls and the rest of the city.",
      "gates":"The tall iron gates stand closed disallowing entrance to the palace.",
   ]));

   set_exits(([
      "west":ROOMS"market5",
      //"south":ROOMS"foyer",
      "north":ROOMS"market4",
      "northwest":ROOMS"market3",
      "northeast":ROOMS"estreet1",
   ]));

   set_invis_exits(({}));
   set_trap_functions(({}),({}),({}));
   set_pre_exit_functions(({}),({}));
   set_post_exit_functions(({}),({}));
}


void reset(){
   ::reset();
   if(!present("worker") && random(4)){
      switch(random(6)){
         case 0:  new("/d/common/mons/worker1")->move(TO);
                  break;
         case 1:  new("/d/common/mons/worker3")->move(TO);
                  break;
         default:  new("/d/common/mons/worker4")->move(TO);
                  break;
      }
   }
}

void init(){
   ::init();

}







