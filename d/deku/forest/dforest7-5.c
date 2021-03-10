#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"8-5",
       "east" : F_ROOMS"6-5",
       "north" : F_ROOMS"7-6",
       "south" : F_ROOMS"7-4",
       "southeast" : F_ROOMS"6-4",
       "southwest" : F_ROOMS"8-4",
       "northeast" : F_ROOMS"6-6",
       "northwest" : F_ROOMS"8-6",
    ] ));
}
