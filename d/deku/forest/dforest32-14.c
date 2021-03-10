#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit WFTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"33-14",
       "south" : F_ROOMS"32-13",
       "north" : F_ROOMS"32-15",
       "northwest" : F_ROOMS"33-15",
       "southwest" : F_ROOMS"33-13",
       
    ] ));
}
