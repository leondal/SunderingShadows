#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"7-8",
       "east" : F_ROOMS"5-8",
       "north" : F_ROOMS"6-9",
       "south" : F_ROOMS"6-7",
       "southeast" : F_ROOMS"5-7",
       "southwest" : F_ROOMS"7-7",
       "northeast" : F_ROOMS"5-9",
       "northwest" : F_ROOMS"7-9",
    ] ));
}
