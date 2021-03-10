#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit WTFTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"24-8",
       "north" : F_ROOMS"23-9",
       "south" : F_ROOMS"23-7",
       "southwest" : F_ROOMS"24-7",
       "northwest" : F_ROOMS"24-9",
    ] ));
}
