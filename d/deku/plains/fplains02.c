#include <std.h>
#include "/d/deku/inherits/forest.h"

inherit FPLAINS;

void create() {
    ::create();
    set_long(TO->query_long()+ "%^BOLD%^%^BLACK%^  The path "+
    "dives into the forest to the southwest of here or continues "+
    "northeast, the trees ever thinning in that direction.%^RESET%^");
    set_exits(([
    "northeast" : P_ROOMS"fplains03",
    "southwest" : P_ROOMS"fplains01",
    ]));
}
    