#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();
    set_short("%^YELLOW%^A dirt trail through the forest.%^RESET%^");
    
    set_long(TO->query_long()+"  %^BOLD%^%^BLACK%^A %^YELLOW%^dirt "+
    "trail%^BOLD%^%^BLACK%^ here leads southwest or east through "+
    "the forest.%^RESET%^");
    set_exits(([
       "west" : F_ROOMS"35-5",
       "east" : F_ROOMS"33-5",
       "north" : F_ROOMS"34-6",
       "south" : F_ROOMS"34-4",
       "southeast" : F_ROOMS"33-4",
       "southwest" : F_ROOMS"35-4",
       "northeast" : F_ROOMS"33-6",
       "northwest" : F_ROOMS"35-6",
    ] ));
    bandit_ambush("southwest","southwest","east",TO);
}
