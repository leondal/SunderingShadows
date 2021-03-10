#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();
    set_long(TO->query_long()+ "  %^BOLD%^%^BLACK%^What appears "+
    "to be a large tower rests in the forest just southwest of "+
    "here.%^RESET%^");
    set_exits(([
       "west" : F_ROOMS"27-9",
       "east" : F_ROOMS"25-9",
       "north" : F_ROOMS"26-10",
       "south" : F_ROOMS"26-8",
       "southeast" : F_ROOMS"25-8",
       "southwest" : F_ROOMS"27-8",
       "northeast" : F_ROOMS"25-10",
       "northwest" : F_ROOMS"27-10",
    ] ));
}
