#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();
    set_short("%^YELLOW%^A dirt trail through the forest.%^RESET%^");
    
    set_long(TO->query_long()+"  %^BOLD%^%^BLACK%^A %^YELLOW%^dirt "+
    "trail%^BOLD%^%^BLACK%^ here continues west to reach the "+
    "gates of verbobone or leads east through the forest.%^RESET%^");
    set_exits(([
       "west" : F_ROOMS"15-5",
       "east" : F_ROOMS"13-5",
       "north" : F_ROOMS"14-6",
       "south" : F_ROOMS"14-4",
       "southeast" : F_ROOMS"13-4",
       "southwest" : F_ROOMS"15-4",
       "northeast" : F_ROOMS"13-6",
       "northwest" : F_ROOMS"15-6",
    ] ));
    bandit_ambush("west","east","east",TO);
}
