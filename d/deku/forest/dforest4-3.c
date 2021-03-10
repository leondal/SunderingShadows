#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();
    set_short("%^YELLOW%^A dirt trail through the forest.%^RESET%^");
    
    set_long(TO->query_long()+"  %^BOLD%^%^BLACK%^A %^YELLOW%^dirt "+
    "trail%^BOLD%^%^BLACK%^ here leads west or northeast through "+
    "the forest.%^RESET%^");
    set_exits(([
       "west" : F_ROOMS"5-3",
       "east" : F_ROOMS"3-3",
       "north" : F_ROOMS"4-4",
       "south" : F_ROOMS"4-2",
       "southeast" : F_ROOMS"3-2",
       "southwest" : F_ROOMS"5-2",
       "northeast" : F_ROOMS"3-4",
       "northwest" : F_ROOMS"5-4",
    ] ));
    bandit_ambush("west","northeast","west",TO);
}
