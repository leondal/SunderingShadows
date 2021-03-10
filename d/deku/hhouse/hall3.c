#include <std.h>
#include "/d/deku/inherits/deku.h"
inherit HH_ROOMS+"hall1i.c";

void create() {
    ::create();
    set_long(TO->query_long()+"There is a room to the south and the hallway "
        "continues east here.");
    set_exits(([
       "west" : HH_ROOMS+"entrance",
       "south" : HH_ROOMS+"living_2",
       "east" : HH_ROOMS+"hall4"
    ] ));
    hauntings();
}
