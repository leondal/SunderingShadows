#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();
    set_long(TO->query_long()+"  %^BOLD%^%^BLACK%^The %^RESET%^"+
    "wall%^BOLD%^%^BLACK%^ of a large structure has risen "+
    "up directly to the north.%^RESET%^");
    add_item("wall","%^BOLD%^%^BLACK%^This large wall is made "+
    "of black bricks and towers some twenty feet high.  It is "+
    "the apparent outer barrier of a large structure.%^RESET%^");
    set_exits(([
       "west" : F_ROOMS"10-9",
       "east" : F_ROOMS"8-9",
       "south" : F_ROOMS"9-8",
       "southeast" : F_ROOMS"8-8",
       "southwest" : F_ROOMS"10-8",
       "northwest" : F_ROOMS"10-10",
    ] ));
}
