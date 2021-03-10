#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();
    set_short("%^YELLOW%^A dirt trail through the forest.%^RESET%^");
    
    set_long(TO->query_long()+"  %^BOLD%^%^BLACK%^A %^YELLOW%^dirt "+
    "trail%^BOLD%^%^BLACK%^ here east or west through "+
    "the forest.%^RESET%^");
    set_exits(([
       "west" : F_ROOMS"6-3",
       "east" : F_ROOMS"4-3",
       "north" : F_ROOMS"5-4",
       "south" : F_ROOMS"5-2",
       "southeast" : F_ROOMS"4-2",
       "southwest" : F_ROOMS"6-2",
       "northeast" : F_ROOMS"4-4",
       "northwest" : F_ROOMS"6-4",
    ] ));
    bandit_ambush("east","west","east",TO);
}
