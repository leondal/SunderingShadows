#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();
     set_long(TO->query_long()+ "  %^BOLD%^%^BLACK%^The large "+
    "north and east walls of verbobone meet and rise up to the "+
    "southeast, blocking the forest path in that direction.%^RESET%^");
    
    set_exits(([
       "east" : F_ROOMS"22-10",
       "west" : F_ROOMS"24-10",
       "north" : F_ROOMS"23-11",
       "south" : F_ROOMS"23-9",
       "northeast" : F_ROOMS"22-11",
       "southwest" : F_ROOMS"24-9",
       "northwest" : F_ROOMS"24-11",

    ] ));
}
