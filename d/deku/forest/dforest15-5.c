#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();
    set_short("%^YELLOW%^A dirt trail through the forest.%^RESET%^");
    
    set_long(TO->query_long()+"  %^BOLD%^%^BLACK%^A %^YELLOW%^dirt "+
    "trail%^BOLD%^%^BLACK%^ here meets the gates of verbobone "+
    "directly to the west or heads off into the forest to the "+
    "east.%^RESET%^");
    set_exits(([
       "east" : F_ROOMS"14-5",
       "north" : F_ROOMS"15-6",
       "south" : F_ROOMS"15-4",
      "west" : "/d/deku/town/road13",
       "southeast" : F_ROOMS"14-4",
       "northeast" : F_ROOMS"14-6",
    ] ));
    bandit_ambush("east","east","east",TO);
}
