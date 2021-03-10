#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"6-2",
       "east" : F_ROOMS"4-2",
       "north" : F_ROOMS"5-3",
       "south" : F_ROOMS"5-1",
       "southeast" : F_ROOMS"4-1",
       "southwest" : F_ROOMS"6-1",
       "northeast" : F_ROOMS"4-3",
       "northwest" : F_ROOMS"6-3",
    ] ));
}
