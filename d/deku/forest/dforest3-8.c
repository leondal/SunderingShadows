#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"4-8",
       "east" : F_ROOMS"2-8",
       "north" : F_ROOMS"3-9",
       "south" : F_ROOMS"3-7",
       "southeast" : F_ROOMS"2-7",
       "southwest" : F_ROOMS"4-7",
       "northeast" : F_ROOMS"2-9",
       "northwest" : F_ROOMS"4-9",
    ] ));
}
