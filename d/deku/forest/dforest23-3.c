#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit WTFTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"24-3",
       "north" : F_ROOMS"23-4",
       "south" : F_ROOMS"23-2",
       "southwest" : F_ROOMS"24-2",
       "northwest" : F_ROOMS"24-4",
       "southeast" : F_ROOMS"23-2",
    ] ));
}
