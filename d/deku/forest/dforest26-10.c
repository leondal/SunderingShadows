#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"27-10",
       "east" : F_ROOMS"25-10",
       "north" : F_ROOMS"26-11",
       "south" : F_ROOMS"26-9",
       "southeast" : F_ROOMS"25-9",
       "southwest" : F_ROOMS"27-9",
       "northeast" : F_ROOMS"25-11",
       "northwest" : F_ROOMS"27-11",
    ] ));
}
