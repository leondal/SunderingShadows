#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();
    set_short("%^YELLOW%^A dirt trail through the forest.%^RESET%^");
    
    set_long(TO->query_long()+"  %^BOLD%^%^BLACK%^A %^YELLOW%^dirt "+
    "trail%^BOLD%^%^BLACK%^ here leads south or north through "+
    "the forest.%^RESET%^");
    set_exits(([
       "west" : F_ROOMS"12-2",
       "east" : F_ROOMS"10-2",
       "north" : F_ROOMS"11-3",
       "south" : F_ROOMS"11-1",
       "southeast" : F_ROOMS"10-1",
       "southwest" : F_ROOMS"12-1",
       "northeast" : F_ROOMS"10-3",
       "northwest" : F_ROOMS"12-3",
    ] ));
    bandit_ambush("north","south","south",TO);
}
