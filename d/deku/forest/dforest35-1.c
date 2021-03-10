#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();
    set_short("%^YELLOW%^A dirt trail through the forest.%^RESET%^");
    
    set_long(TO->query_long()+"  %^BOLD%^%^BLACK%^A %^YELLOW%^dirt "+
    "trail%^BOLD%^%^BLACK%^ here leads northwest through "+
    "the forest or south through thick debris and undergrowth into "+
    "a more healthy part of the forest.%^RESET%^");
    set_exits(([
       "west" : F_ROOMS"36-1",
       "east" : F_ROOMS"34-1",
       "north" : F_ROOMS"35-2",
       "northeast" : F_ROOMS"34-2",
       "northwest" : F_ROOMS"36-2",
       "south" : "/d/deku/forest/forest3"
    ] ));
    bandit_ambush("northwest","northwest","south",TO);
}
