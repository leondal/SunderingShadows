#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();
    set_long(TO->query_long()+ "  %^BOLD%^%^BLACK%^What appears "+
    "to be a large tower rests in the forest just east of "+
    "here.%^RESET%^");
    set_exits(([
       "west" : F_ROOMS"29-8",
       "east" : F_ROOMS"27-8",
       "north" : F_ROOMS"28-9",
       "south" : F_ROOMS"28-7",
       "southeast" : F_ROOMS"27-7",
       "southwest" : F_ROOMS"29-7",
       "northeast" : F_ROOMS"27-9",
       "northwest" : F_ROOMS"29-9",
    ] ));
}
