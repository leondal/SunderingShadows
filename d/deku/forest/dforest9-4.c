#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();
     set_short("%^YELLOW%^A dirt trail through the forest.%^RESET%^");
    
    set_long(TO->query_long()+"  %^BOLD%^%^BLACK%^A %^YELLOW%^dirt "+
    "trail%^BOLD%^%^BLACK%^ here leads west or southeast through "+
    "the forest.%^RESET%^");
    set_exits(([
       "west" : F_ROOMS"10-4",
       "east" : F_ROOMS"8-4",
       "north" : F_ROOMS"9-5",
       "south" : F_ROOMS"9-3",
       "southeast" : F_ROOMS"8-3",
       "southwest" : F_ROOMS"10-3",
       "northeast" : F_ROOMS"8-5",
       "northwest" : F_ROOMS"10-5",
    ] ));
    bandit_ambush("west","southwest",0,TO);
}
