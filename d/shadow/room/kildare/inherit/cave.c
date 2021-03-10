#include <std.h>
#include "../kildare.h"

inherit ROOM;
void create(){
   ::create();
   set_indoors(1);
   set_property("light",1);
   set_terrain(BUILT_TUNNEL);
   set_travel(DIRT_ROAD);
   set_name("Sloping Cavern");
   set_short("Sloping Cavern");
   set_smell("default","You smell the stale air of the caverns.");
   set_listen("default","You hear the reverberance of echoes throughout the caves.");
   set_items(([
      ({"cavern","walls","wall"}) : "The dark walls of this cavern seem to be "+
      "hewn rather than naturally carved as the rest of Echoes Mountains.",
      ({"floor","ceiling","stone"}) : "The ceiling seems to be very roughly hewn "+
      "while the dark stone floor has been worn smooth."
      ]));

}
