#include <std.h>
#include "/d/deku/inherits/deku.h"
inherit HH_ROOMS+"hall1i.c";

void create() {
    ::create();
    set_long(TO->query_long()+"The hall ends here with a bedroom to the south.");
    set_exits(([
       "west" : HH_ROOMS+"hall5",
       "south" : HH_ROOMS+"bed4"
    ] ));
    hauntings();
}
