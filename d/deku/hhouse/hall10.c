#include <std.h>
#include "/d/deku/inherits/deku.h"
inherit HH_ROOMS+"hall1i.c";

void create() {
    ::create();
    set_long(TO->query_long()+"There is a door towards the east.  The hallway "
      "runs north / south here.");
    set_exits(([
       "north" : HH_ROOMS+"landing",
       "south" : HH_ROOMS+"hall9",
       "east" : HH_ROOMS+"box_r"
    ] ));
    hauntings();
}
