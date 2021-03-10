#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();
    set_long(TO->query_long()+ "  %^BOLD%^%^BLACK%^What appears "+
    "to be a large tower rests in the forest just south of "+
    "here.%^RESET%^");
    set_exits(([
       "west" : F_ROOMS"28-9",
       "east" : F_ROOMS"26-9",
       "north" : F_ROOMS"27-10",
       "south" : F_ROOMS"27-8",
       "southeast" : F_ROOMS"26-8",
       "southwest" : F_ROOMS"28-8",
       "northeast" : F_ROOMS"26-10",
       "northwest" : F_ROOMS"28-10",
    ] ));
}
