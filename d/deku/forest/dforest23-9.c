#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit WTFTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"24-9",
       "north" : F_ROOMS"23-10",
       "south" : F_ROOMS"23-8",
       "southwest" : F_ROOMS"24-8",
       "northwest" : F_ROOMS"24-10",
       "northeast" : F_ROOMS"22-10",
    ] ));
}
