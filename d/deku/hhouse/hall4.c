#include <std.h>
#include "/d/deku/inherits/deku.h"

inherit HH_ROOMS+"hall1i.c";
void create() {
    ::create();
    set_long(TO->query_long()+"The hallway ends here with a room to the south.");
    set_exits(([
       "west" : HH_ROOMS+"hall3",
       "south" : HH_ROOMS+"living_3"
    ] ));
    hauntings();
}
