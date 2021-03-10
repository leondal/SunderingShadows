#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();
    set_short("%^YELLOW%^A dirt trail through the forest.%^RESET%^");
    
    set_long(TO->query_long()+"  %^BOLD%^%^BLACK%^A %^YELLOW%^dirt "+
    "trail%^BOLD%^%^BLACK%^ here leads west or southeast through "+
    "the forest.%^RESET%^");
    set_exits(([
       "west" : F_ROOMS"12-5",
       "east" : F_ROOMS"10-5",
       "north" : F_ROOMS"11-6",
       "south" : F_ROOMS"11-4",
       "southeast" : F_ROOMS"10-4",
       "southwest" : F_ROOMS"12-4",
       "northeast" : F_ROOMS"10-6",
       "northwest" : F_ROOMS"12-6",
    ] ));
    bandit_ambush("west","southeast","west",TO);
}
