#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();
    set_long(TO->query_long()+ "  %^BOLD%^%^BLACK%^The large "+
    "south and east walls of verbobone meet and rise up to the "+
    "northwest, blocking the forest path in that direction.%^RESET%^");
    
    set_exits(([
       "east" : F_ROOMS"14-2",
       "south" : F_ROOMS"15-1",
       "southeast" : F_ROOMS"14-1",
       "west" : F_ROOMS"16-2",
       "southwest" : F_ROOMS"16-1",
       "northeast" : F_ROOMS"14-3",
       "north" : F_ROOMS"15-3",
    ] ));
}
