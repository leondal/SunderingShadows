#include <std.h>
#include "/d/deku/inherits/deku.h"
inherit "/d/deku/inherits/hideout_inh.c";

void create() {
    ::create();

   set_long(TO->query_long() + "%^YELLOW%^  An open doorway leads "+
   "out of this room to the north and another to the east.  "+
   "An %^BOLD%^%^GREEN%^oak door%^YELLOW%^ is set into the center "+
   "of the west wall.%^RESET%^");

   set_exits(([
       "north" : BH_ROOMS+"hideout1",
       "east" : BH_ROOMS+"hideout3",
       "west" : BH_ROOMS+"barracks",
    ] ));

   set_door("oak door",BH_ROOMS+"barracks", "west");
   set_door_description("oak door","%^GREEN%^This door is made "+
   "from four slabs of oak that have been tightly bound together "+
   "with a thick and coarse rope.%^RESET%^");
}
