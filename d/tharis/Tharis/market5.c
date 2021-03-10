//market5.c

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
walls of the palace can be seen up the mountain road. The crowd bustles
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
      "northwest":ROOMS"wstreet1",
      "east":ROOMS"market6",
      "north":ROOMS"market3",
      "south":"/d/tharis/palace/mountain/m32",
      "northeast":ROOMS"market4",
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







