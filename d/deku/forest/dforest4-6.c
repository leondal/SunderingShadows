#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"5-6",
       "east" : F_ROOMS"3-6",
       "north" : F_ROOMS"4-7",
       "south" : F_ROOMS"4-5",
       "southeast" : F_ROOMS"3-5",
       "southwest" : F_ROOMS"5-5",
       "northeast" : F_ROOMS"3-7",
       "northwest" : F_ROOMS"5-7",
    ] ));
}
