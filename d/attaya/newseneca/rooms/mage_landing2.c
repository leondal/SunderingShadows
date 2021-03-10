//~Circe~ 1/2/07 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit MAGELANDING;

void create(){
   ::create();
   set_long(::query_long()+"\nTo the east here is a room with "+
      "an open %^BOLD%^%^BLACK%^archway %^RESET%^leading into "+
      "what appears to be a "+
      "%^MAGENTA%^components shop%^RESET%^, judging from the "+
      "array of unusual materials arranged throughout.\n");
   add_item("archway","%^BOLD%^%^BLACK%^The archway is fashioned "+
      "from the smooth stone of the walls.  Like the walls, "+
      "it seems to have been shaped or grown rather than hewn.%^RESET%^");
   set_exits(([
      "down" : ROOMS"mage_landing1",
      "up" : ROOMS"mage_landing3",
      "east" : ROOMS"mage_comps"
   ]));
}