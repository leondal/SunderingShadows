#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit WTFTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"24-4",
       "north" : F_ROOMS"23-5",
       "south" : F_ROOMS"23-3",
       "southwest" : F_ROOMS"24-3",
       "northwest" : F_ROOMS"24-5",
    ] ));
}
