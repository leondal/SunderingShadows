#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"10-3",
       "east" : F_ROOMS"8-3",
       "north" : F_ROOMS"9-4",
       "south" : F_ROOMS"9-2",
       "southeast" : F_ROOMS"8-2",
       "southwest" : F_ROOMS"10-2",
       "northeast" : F_ROOMS"8-4",
       "northwest" : F_ROOMS"10-4",
    ] ));
}
