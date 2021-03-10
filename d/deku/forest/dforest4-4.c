#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"5-4",
       "east" : F_ROOMS"3-4",
       "north" : F_ROOMS"4-5",
       "south" : F_ROOMS"4-3",
       "southeast" : F_ROOMS"3-3",
       "southwest" : F_ROOMS"5-3",
       "northeast" : F_ROOMS"3-5",
       "northwest" : F_ROOMS"5-5",
    ] ));
}
