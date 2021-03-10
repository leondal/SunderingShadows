#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();
    set_short("%^YELLOW%^A dirt trail through the forest.%^RESET%^");
    
    set_long(TO->query_long()+"  %^BOLD%^%^BLACK%^A %^YELLOW%^dirt "+
    "trail%^BOLD%^%^BLACK%^ here leads south or northeast through "+
    "the forest.%^RESET%^");
    set_exits(([
       "west" : F_ROOMS"37-3",
       "east" : F_ROOMS"35-3",
       "north" : F_ROOMS"36-4",
       "south" : F_ROOMS"36-2",
       "southeast" : F_ROOMS"35-2",
       "southwest" : F_ROOMS"37-2",
       "northeast" : F_ROOMS"35-4",
       "northwest" : F_ROOMS"37-4",
    ] ));
    bandit_ambush("south","south","northeast",TO);
}
