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
       "west" : F_ROOMS"9-7",
       "east" : F_ROOMS"7-7",
       "north" : F_ROOMS"8-8",
       "south" : F_ROOMS"8-6",
       "southeast" : F_ROOMS"7-6",
       "southwest" : F_ROOMS"9-6",
       "northeast" : F_ROOMS"7-8",
       "northwest" : F_ROOMS"9-8",
    ] ));
    bandit_ambush("north","south","south",TO);
}

