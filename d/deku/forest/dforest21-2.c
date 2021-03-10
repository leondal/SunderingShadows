#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();
    set_long(TO->query_long()+"  %^BOLD%^%^BLACK%^The south gates "+
    "of the town of verbobone are directly north of here."+
    "%^RESET%^");
    set_exits(([
       "east" : F_ROOMS"20-2",
       "south" : F_ROOMS"21-1",
       "southeast" : F_ROOMS"20-1",
       "west" : F_ROOMS"22-2",
       "southwest" : F_ROOMS"22-1",
       "north" : "/d/deku/town/sroad3",
    ] ));
}
