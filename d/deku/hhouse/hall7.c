#include <std.h>
#include "/d/deku/inherits/deku.h"
inherit HH_ROOMS+"hall1i.c";

void create() {
    ::create();
    set_long(TO->query_long()+"There is a bedroom to the south.  The hall "
      "continues to the east and west as well as northward.");
    set_exits(([
       "north" : HH_ROOMS+"hall9",
       "south" : HH_ROOMS+"bed1",
       "west" : HH_ROOMS+"hall8",
       "east" : HH_ROOMS+"stair"
    ] ));
    hauntings();
}

