#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();
    set_short("%^YELLOW%^A dirt trail through the forest.%^RESET%^");
    
    set_long(TO->query_long()+"  %^BOLD%^%^BLACK%^A %^YELLOW%^dirt "+
    "trail%^BOLD%^%^BLACK%^ here meets the gates of verbobone "+
    "directly to the east or heads off into the forest to the "+
    "southwest.%^RESET%^");
    set_exits(([
       "west" : F_ROOMS"24-5",
       "north" : F_ROOMS"23-6",
       "south" : F_ROOMS"23-4",
       "east" : "/d/deku/town/road2",
       "southwest" : F_ROOMS"24-4",
       "northwest" : F_ROOMS"24-6",
    ] ));
}
