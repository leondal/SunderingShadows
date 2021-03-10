#include <std.h>
#include "/d/deku/inherits/deku.h"
inherit HH_ROOMS+"hall1i.c";

void create() {
    ::create();
    set_long(TO->query_long()+"There is a single room here to the south and the hallway continues east.");
    set_exits(([
       "west" : HH_ROOMS+"stair",
       "south" : HH_ROOMS+"bed3",
       "east" : HH_ROOMS+"hall6"
    ] ));
    hauntings();
}
