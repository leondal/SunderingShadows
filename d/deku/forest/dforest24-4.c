#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();
    set_short("%^YELLOW%^A dirt trail through the forest.%^RESET%^");
    
    set_long(TO->query_long()+"  %^BOLD%^%^BLACK%^A %^YELLOW%^dirt "+
    "trail%^BOLD%^%^BLACK%^ here leads up to the gates of verbobone "+
    "to the northeast or continues into the forest to the "+
    "southwest.%^RESET%^");
    
    set_exits(([
       "west" : F_ROOMS"25-4",
       "east" : F_ROOMS"23-4",
       "north" : F_ROOMS"24-5",
       "south" : F_ROOMS"24-3",
       "southeast" : F_ROOMS"23-3",
       "southwest" : F_ROOMS"25-3",
       "northeast" : F_ROOMS"23-5",
       "northwest" : F_ROOMS"25-5",
    ] ));
    bandit_ambush("southwest","northeast","southwest",TO);
}
