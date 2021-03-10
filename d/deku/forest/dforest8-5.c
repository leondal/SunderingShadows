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
       "west" : F_ROOMS"9-5",
       "east" : F_ROOMS"7-5",
       "north" : F_ROOMS"8-6",
       "south" : F_ROOMS"8-4",
       "southeast" : F_ROOMS"7-4",
       "southwest" : F_ROOMS"9-4",
       "northeast" : F_ROOMS"7-6",
       "northwest" : F_ROOMS"9-6",
    ] ));
    bandit_ambush("north","south","south",TO);
}
