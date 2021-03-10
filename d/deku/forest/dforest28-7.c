#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();
    set_long(TO->query_long()+ "  %^BOLD%^%^BLACK%^What appears "+
    "to be a large tower rests in the forest just northeast "+
    "here.%^RESET%^");
    set_exits(([
       "west" : F_ROOMS"29-7",
       "east" : F_ROOMS"27-7",
       "north" : F_ROOMS"28-8",
       "south" : F_ROOMS"28-6",
       "southeast" : F_ROOMS"27-6",
       "southwest" : F_ROOMS"29-6",
       "northeast" : F_ROOMS"27-8",
       "northwest" : F_ROOMS"29-8",
    ] ));
}
