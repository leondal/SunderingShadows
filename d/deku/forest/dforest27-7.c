#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();
    set_short("%^YELLOW%^A dirt trail through the forest.%^RESET%^");
    
    set_long(TO->query_long()+"  %^BOLD%^%^BLACK%^A %^YELLOW%^dirt "+
    "trail%^BOLD%^%^BLACK%^ here leads south through "+
    "the forest or north up to what appears to be a "+
    "tower.");
    set_exits(([
       "west" : F_ROOMS"28-7",
       "east" : F_ROOMS"26-7",
       "north" : F_ROOMS"27-8",
       "south" : F_ROOMS"27-6",
       "southeast" : F_ROOMS"26-6",
       "southwest" : F_ROOMS"28-6",
       "northeast" : F_ROOMS"26-8",
       "northwest" : F_ROOMS"28-8",
    ] ));
    bandit_ambush("south","north","south",TO);
}
