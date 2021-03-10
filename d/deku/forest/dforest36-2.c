#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();
    set_short("%^YELLOW%^A dirt trail through the forest.%^RESET%^");
    
    set_long(TO->query_long()+"  %^BOLD%^%^BLACK%^A %^YELLOW%^dirt "+
    "trail%^BOLD%^%^BLACK%^ here leads southeast or north through "+
    "the forest.%^RESET%^");
    set_exits(([
       "west" : F_ROOMS"37-2",
       "east" : F_ROOMS"35-2",
       "north" : F_ROOMS"36-3",
       "south" : F_ROOMS"36-1",
       "southeast" : F_ROOMS"35-1",
       "southwest" : F_ROOMS"37-1",
       "northeast" : F_ROOMS"35-3",
       "northwest" : F_ROOMS"37-3",
    ] ));
    bandit_ambush("north","north","southeast",TO);
}
