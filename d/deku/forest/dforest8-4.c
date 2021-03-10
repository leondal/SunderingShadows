#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();
    set_short("%^YELLOW%^A dirt trail through the forest.%^RESET%^");
    
    set_long(TO->query_long()+"  %^BOLD%^%^BLACK%^A %^YELLOW%^dirt "+
    "trail%^BOLD%^%^BLACK%^ here leads north through the forest "+
    "and splits directly to the south where it continues "+
    "east or west.");

    set_exits(([
       "west" : F_ROOMS"9-4",
       "east" : F_ROOMS"7-4",
       "north" : F_ROOMS"8-5",
       "south" : F_ROOMS"8-3",
       "southeast" : F_ROOMS"7-3",
       "southwest" : F_ROOMS"9-3",
       "northeast" : F_ROOMS"7-5",
       "northwest" : F_ROOMS"9-5",
    ] ));
    bandit_ambush("north","north","south",TO);
}
