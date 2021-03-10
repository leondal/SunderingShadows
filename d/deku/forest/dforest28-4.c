#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();
    set_short("%^YELLOW%^A dirt trail through the forest.%^RESET%^");
    
    set_long(TO->query_long()+"  %^BOLD%^%^BLACK%^A %^YELLOW%^dirt "+
    "trail%^BOLD%^%^BLACK%^ here leads north or southeast through "+
    "the forest.%^RESET%^");
    set_exits(([
       "west" : F_ROOMS"29-4",
       "east" : F_ROOMS"27-4",
       "north" : F_ROOMS"28-5",
       "south" : F_ROOMS"28-3",
       "southeast" : F_ROOMS"27-3",
       "southwest" : F_ROOMS"29-3",
       "northeast" : F_ROOMS"27-5",
       "northwest" : F_ROOMS"29-5",
    ] ));
    bandit_ambush("north","north","southeast",TO);
}
