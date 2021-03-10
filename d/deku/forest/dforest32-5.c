#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit LAKEBANK;

void create() {
    ::create();
    set_long(TO->query_long()+"  %^CYAN%^A %^YELLOW%^dirt "+
    "trail%^CYAN%^ here leads off into the forest to west.");
    set_exits(([
       "west" : F_ROOMS"33-5",
       "north" : F_ROOMS"32-6",
       "south" : F_ROOMS"32-4",
       "southwest" : F_ROOMS"33-4",
       "northwest" : F_ROOMS"33-6",
    ] ));
}
