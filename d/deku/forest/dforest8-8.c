#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();
    set_short("%^YELLOW%^A dirt trail through the forest.%^RESET%^");
    
    set_long(TO->query_long()+"  %^BOLD%^%^BLACK%^A %^YELLOW%^dirt "+
    "trail%^BOLD%^%^BLACK%^ here leads north through "+
    "the forest to the blacktongue keep or south back into the "+
    "forest.");

    set_exits(([
       "west" : F_ROOMS"9-8",
       "east" : F_ROOMS"7-8",
       "north" : F_ROOMS"8-9",
       "south" : F_ROOMS"8-7",
       "southeast" : F_ROOMS"7-7",
       "southwest" : F_ROOMS"9-7",
       "northeast" : F_ROOMS"7-9",
       "northwest" : F_ROOMS"9-9",
    ] ));
    bandit_ambush("north","south","north",TO);
}
