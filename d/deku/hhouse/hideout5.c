#include <std.h>
#include "/d/deku/inherits/deku.h"
inherit "/d/deku/inherits/hideout_inh.c";

void create() {
    ::create();
   set_long(TO->query_long() + "%^YELLOW%^  An open doorway leads "+
   "out of this room to the north and another to the south.%^RESET%^");
  
   set_exits(([
       "north" : BH_ROOMS+"hideout4",
       "south" : BH_ROOMS+"hideout6",
   ] ));
}
