#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();
    set_short("%^YELLOW%^A dirt trail through the forest.%^RESET%^");
    set_long(TO->query_long()+"  %^BOLD%^%^BLACK%^A %^YELLOW%^dirt "+
    "trail%^BOLD%^%^BLACK%^ here leads north to "+
    "the drawbridge of the infamous keep blacktongue or back into "+
    "the forest to the south.");
  
    set_listen("default","Strange sounds echo throughough the "+
    "forest and mingle with those radiating outward from within "+
    "the keep.");
     
    set_exits(([
       "west" : F_ROOMS"9-9",
       "east" : F_ROOMS"7-9",
       "north" : "/d/deku/keep/rooms/draw",
       "south" : F_ROOMS"8-8",
       "southeast" : F_ROOMS"7-8",
       "southwest" : F_ROOMS"9-8",
    ] ));
    bandit_ambush("south","south","south",TO);
}
