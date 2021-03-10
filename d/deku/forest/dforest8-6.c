#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();
    set_short("%^YELLOW%^A dirt trail through the forest.%^RESET%^");
    
    set_long(TO->query_long()+"  %^BOLD%^%^BLACK%^A %^YELLOW%^dirt "+
    "trail%^BOLD%^%^BLACK%^ here leads north or south through "+
    "the forest.");

    set_exits(([
       "west" : F_ROOMS"9-6",
       "east" : F_ROOMS"7-6",
       "north" : F_ROOMS"8-7",
       "south" : F_ROOMS"8-5",
       "southeast" : F_ROOMS"7-5",
       "southwest" : F_ROOMS"9-5",
       "northeast" : F_ROOMS"7-7",
       "northwest" : F_ROOMS"9-7",
    ] ));
    bandit_ambush("north","south","south",TO);
}
