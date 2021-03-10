#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();
    set_long(TO->query_long()+ "  %^BOLD%^%^BLACK%^The large "+
    "north and west walls of verbobone meet and rise up to the "+
    "southwest, blocking the forest path in that direction.%^RESET%^");
    
    set_exits(([
       "east" : F_ROOMS"14-10",
       "north" : F_ROOMS"15-11",
       "southeast" : F_ROOMS"14-9",
       "northeast" : F_ROOMS"14-11",
       "west" : F_ROOMS"16-10",
       "northwest" : F_ROOMS"16-11",
       "south" : F_ROOMS"15-9",
    ] ));
}
