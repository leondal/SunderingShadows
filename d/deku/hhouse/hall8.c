#include <std.h>
#include "/d/deku/inherits/deku.h"
inherit HH_ROOMS+"hall1i.c";

void create() {
    ::create();
    set_long(TO->query_long()+"The hall ends here with a bedroom to the south.");
    set_exits(([
       "east" : HH_ROOMS+"hall7",
       "south" : HH_ROOMS+"bed2i"
    ] ));
    hauntings();
}
