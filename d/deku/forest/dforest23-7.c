#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit WTFTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"24-7",
       "north" : F_ROOMS"23-8",
       "south" : F_ROOMS"23-6",
       "southwest" : F_ROOMS"24-6",
       "northwest" : F_ROOMS"24-8",
    ] ));
}
