#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"25-3",
       "east" : F_ROOMS"23-3",
       "north" : F_ROOMS"24-4",
       "south" : F_ROOMS"24-2",
       "southeast" : F_ROOMS"23-2",
       "southwest" : F_ROOMS"25-2",
       "northeast" : F_ROOMS"23-4",
       "northwest" : F_ROOMS"25-4",
    ] ));
}
