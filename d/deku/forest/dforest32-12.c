#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit RIVERBANK;

void create() {
    ::create();
   set_long(TO->query_long()+"  %^CYAN%^The river runs out "+
   "of the forest from the west and continues northeast into "+
   "the forest.  Travel to the northeast is made impossible "+
   "by the thick undergrowth that sprouts up in that direction.");
      
    set_exits(([
       "west" : F_ROOMS"33-12",
       "north" : F_ROOMS"32-13",
       "northwest" : F_ROOMS"33-13",
    ] ));
}
