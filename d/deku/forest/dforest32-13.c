#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit WFTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"33-13",
       "south" : F_ROOMS"32-12",
       "north" : F_ROOMS"32-14",
       "northwest" : F_ROOMS"33-14",
       "southwest" : F_ROOMS"33-12",
       
    ] ));
}
