#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();
    set_short("%^YELLOW%^A dirt trail through the forest.%^RESET%^");
    
    set_long(TO->query_long()+"  %^BOLD%^%^BLACK%^A %^YELLOW%^dirt "+
    "trail%^BOLD%^%^BLACK%^ here leads southwest or north through "+
    "the forest.");
    set_exits(([
       "west" : F_ROOMS"28-6",
       "east" : F_ROOMS"26-6",
       "north" : F_ROOMS"27-7",
       "south" : F_ROOMS"27-5",
       "southeast" : F_ROOMS"26-5",
       "southwest" : F_ROOMS"28-5",
       "northeast" : F_ROOMS"26-7",
       "northwest" : F_ROOMS"28-7",
    ] ));
    bandit_ambush("north","southwest","southwest",TO);
}
