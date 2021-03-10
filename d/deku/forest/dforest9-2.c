#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"10-2",
       "east" : F_ROOMS"8-2",
       "north" : F_ROOMS"9-3",
       "south" : F_ROOMS"9-1",
       "southeast" : F_ROOMS"8-1",
       "southwest" : F_ROOMS"10-1",
       "northeast" : F_ROOMS"8-3",
       "northwest" : F_ROOMS"10-3",
    ] ));
}
