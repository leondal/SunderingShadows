#include <std.h>
#include "/d/deku/inherits/deku.h"
inherit HH_ROOMS+"hall1i.c";

void create() {
    ::create();
    set_long(TO->query_long()+"There is a bedroom to the east and the hallway "
      "runs north / south here.");
    set_exits(([
       "north" : HH_ROOMS+"hall10",
       "south" : HH_ROOMS+"hall7",
       "east" : HH_ROOMS+"bed5"
    ] ));
    hauntings();
}
