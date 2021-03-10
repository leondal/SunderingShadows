#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"4-7",
       "east" : F_ROOMS"2-7",
       "north" : F_ROOMS"3-8",
       "south" : F_ROOMS"3-6",
       "southeast" : F_ROOMS"2-6",
       "southwest" : F_ROOMS"4-6",
       "northeast" : F_ROOMS"2-8",
       "northwest" : F_ROOMS"4-8",
    ] ));
}
