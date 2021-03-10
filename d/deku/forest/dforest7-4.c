#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"8-4",
       "east" : F_ROOMS"6-4",
       "north" : F_ROOMS"7-5",
       "south" : F_ROOMS"7-3",
       "southeast" : F_ROOMS"6-3",
       "southwest" : F_ROOMS"8-3",
       "northeast" : F_ROOMS"6-5",
       "northwest" : F_ROOMS"8-5",
    ] ));
}
