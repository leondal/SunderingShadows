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
       "west" : F_ROOMS"4-4",
       "east" : F_ROOMS"2-4",
       "north" : F_ROOMS"3-5",
       "south" : F_ROOMS"3-3",
       "southeast" : F_ROOMS"2-3",
       "southwest" : F_ROOMS"4-3",
       "northeast" : F_ROOMS"2-5",
       "northwest" : F_ROOMS"4-5",
    ] ));
    bandit_ambush("northeast","southwest","northeast",TO);
}
