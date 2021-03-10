#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();
    set_short("%^YELLOW%^A dirt trail through the forest.%^RESET%^");
    
    set_long(TO->query_long()+"  %^BOLD%^%^BLACK%^A %^YELLOW%^dirt "+
    "trail%^BOLD%^%^BLACK%^ here leads north through the "+
    "dark forest or south to a part of the forest that appears "+
    "to have some life left in it.%^RESET%^");
    set_exits(([
       "west" : F_ROOMS"12-1",
       "east" : F_ROOMS"10-1",
       "north" : F_ROOMS"11-2",
       "south" : F_ROOMS"11-al1",
       "northeast" : F_ROOMS"10-2",
       "northwest" : F_ROOMS"12-2",
    ] ));
    bandit_ambush("south","north","north",TO);
}
