#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit WFTRAIL;

void create() {
    ::create();
    set_long(TO->query_long()+ "  %^BOLD%^%^BLACK%^An enclosed "+
    "path opens up and continues north here.%^RESET%^");
    set_exits(([
       "north" : F_ROOMS"37-17",
       "east" : F_ROOMS"36-16",
       "south" : F_ROOMS"37-15",
       "southeast" : F_ROOMS"36-15",       
    ] ));
}
