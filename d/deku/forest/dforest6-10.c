#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();
    set_long(TO->query_long()+"  %^BOLD%^%^BLACK%^The %^RESET%^"+
    "wall%^BOLD%^%^BLACK%^ of a large structure has risen "+
    "up directly to the west.%^RESET%^");
    add_item("wall","%^BOLD%^%^BLACK%^This large wall is made "+
    "of black bricks and towers some twenty feet high.  It is "+
    "the apparent outer defense of a large structure.%^RESET%^");
    set_exits(([
       "east" : F_ROOMS"5-10",
       "north" : F_ROOMS"6-11",
       "south" : F_ROOMS"6-9",
       "southeast" : F_ROOMS"5-9",
       "southwest" : F_ROOMS"7-9",
       "northeast" : F_ROOMS"5-11",
    ] ));
}
