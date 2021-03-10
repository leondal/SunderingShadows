#include <std.h>
#include "/d/deku/inherits/deku.h"
inherit HH_ROOMS+"hall1i.c";

void create() {
    ::create();
    set_long(TO->query_long()+"This is the end of the hallway in this section "
      "and there are three openings into rooms here.");
    set_exits(([
       "north" : HH_ROOMS+"kitchen",
       "south" : HH_ROOMS+"entrance",
       "west" : HH_ROOMS+"dining",
       "east" : HH_ROOMS+"drawing"
    ] ));
    hauntings();
}
