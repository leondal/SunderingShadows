#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();
    set_short("%^YELLOW%^A dirt trail through the forest.%^RESET%^");
    
    set_long(TO->query_long()+"  %^BOLD%^%^BLACK%^A %^YELLOW%^dirt "+
    "trail%^BOLD%^%^BLACK%^ here leads east or west through "+
    "the forest.%^RESET%^");
    set_exits(([
       "west" : F_ROOMS"8-3",
       "east" : F_ROOMS"6-3",
       "north" : F_ROOMS"7-4",
       "south" : F_ROOMS"7-2",
       "southeast" : F_ROOMS"6-2",
       "southwest" : F_ROOMS"8-2",
       "northeast" : F_ROOMS"6-4",
       "northwest" : F_ROOMS"8-4",
    ] ));
    bandit_ambush("east","west","east",TO);
}
