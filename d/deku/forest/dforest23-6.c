#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit WTFTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"24-6",
       "north" : F_ROOMS"23-7",
       "south" : F_ROOMS"23-5",
       "southwest" : F_ROOMS"24-5",
       "northwest" : F_ROOMS"24-7",
    ] ));
}
