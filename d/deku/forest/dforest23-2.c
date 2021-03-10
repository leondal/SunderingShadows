#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();
     set_long(TO->query_long()+ "  %^BOLD%^%^BLACK%^The large "+
    "south and west walls of verbobone meet and rise up to the "+
    "northeast, blocking the forest path in that direction.%^RESET%^");
    
    set_exits(([
       "west" : F_ROOMS"24-2",
       "north" : F_ROOMS"23-3",
       "south" : F_ROOMS"23-1",
       "southwest" : F_ROOMS"24-1",
       "northwest" : F_ROOMS"24-3",
       "east" : F_ROOMS"22-2",
       "southeast" : F_ROOMS"22-1"
    ] ));
}
