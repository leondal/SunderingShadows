#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit SHORETRAIL;

void create() {
    ::create();
    set_short("%^YELLOW%^A dirt trail through the forest.%^RESET%^");
    
    set_long(TO->query_long()+"  %^BOLD%^%^BLACK%^A %^YELLOW%^dirt "+
    "trail%^BOLD%^%^BLACK%^ here leads southwest into the forest "+
    "or comes up to what appears to be an old dock to the "+
    "northeast.");
    set_exits(([
       "west" : F_ROOMS"3-5",
       "north" : F_ROOMS"2-6",
       "south" : F_ROOMS"2-4",
       "southwest" : F_ROOMS"3-4",
       "northeast" : "/d/shadow/virtual/sea/deku.dock"
,      "northwest" : F_ROOMS"3-6",
    ] ));
    bandit_ambush("northeast","southwest","northeast",TO);
}
