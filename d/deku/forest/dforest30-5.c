#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit LAKEBANK;

void create() {
    ::create();
    set_long(TO->query_long()+"  %^CYAN%^A %^YELLOW%^dirt "+
    "trail%^CYAN%^ here leads off into the forest to the east.");
    set_exits(([
       "east" : F_ROOMS"29-5",
       "north" : F_ROOMS"30-6",
       "south" : F_ROOMS"30-4",
       "southeast" : F_ROOMS"29-4",
       "northeast" : F_ROOMS"29-6",       
    ] ));
}
