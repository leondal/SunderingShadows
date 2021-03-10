#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"25-2",
       "east" : F_ROOMS"23-2",
       "north" : F_ROOMS"24-3",
       "south" : F_ROOMS"24-1",
       "southeast" : F_ROOMS"23-1",
       "southwest" : F_ROOMS"25-1",
       "northeast" : F_ROOMS"23-3",
       "northwest" : F_ROOMS"25-3",
    ] ));
}
