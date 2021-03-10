#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"6-7",
       "east" : F_ROOMS"4-7",
       "north" : F_ROOMS"5-8",
       "south" : F_ROOMS"5-6",
       "southeast" : F_ROOMS"4-6",
       "southwest" : F_ROOMS"6-6",
       "northeast" : F_ROOMS"4-8",
       "northwest" : F_ROOMS"6-8",
    ] ));
}
