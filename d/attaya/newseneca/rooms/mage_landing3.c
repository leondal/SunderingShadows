//~Circe~ 1/3/07 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit MAGELANDING;

void create(){
   ::create();
   set_long(::query_long()+"\nTo the east here is a room with "+
      "an open %^BOLD%^%^BLACK%^archway %^RESET%^leading into "+
      "what appears to be a %^YELLOW%^golden "+
      "shop%^RESET%^ selling %^BOLD%^scrolls %^RESET%^"+
      "and %^ORANGE%^books%^RESET%^.\n");
   add_item("archway","%^BOLD%^%^BLACK%^The archway is fashioned "+
      "from the smooth stone of the walls.  Like the walls, "+
      "it seems to have been shaped or grown rather than hewn.%^RESET%^");
   set_exits(([
      "down" : ROOMS"mage_landing2",
      "up" : ROOMS"mage_landing4",
      "east" : ROOMS"mage_store"
   ]));
}