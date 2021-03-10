#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();
    set_short("%^YELLOW%^A dirt trail through the forest.%^RESET%^");
    
    set_long(TO->query_long()+"  %^BOLD%^%^BLACK%^A %^YELLOW%^dirt "+
    "trail%^BOLD%^%^BLACK%^ here leads southwest or northeast through "+
    "the forest.%^RESET%^");
    set_exits(([
       "west" : F_ROOMS"36-4",
       "east" : F_ROOMS"34-4",
       "north" : F_ROOMS"35-5",
       "south" : F_ROOMS"35-3",
       "southeast" : F_ROOMS"34-3",
       "southwest" : F_ROOMS"36-3",
       "northeast" : F_ROOMS"34-5",
       "northwest" : F_ROOMS"36-5",
    ] ));
    bandit_ambush("southwest","northeast","northeast",TO);
}
