#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"4-10",
       "east" : F_ROOMS"2-10",
       "north" : F_ROOMS"3-11",
       "south" : F_ROOMS"3-9",
       "southeast" : F_ROOMS"2-9",
       "southwest" : F_ROOMS"4-9",
       "northeast" : F_ROOMS"2-11",
       "northwest" : F_ROOMS"4-11",
    ] ));
}
