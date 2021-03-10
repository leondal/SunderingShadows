#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"14-2",
       "east" : F_ROOMS"12-2",
       "north" : F_ROOMS"13-3",
       "south" : F_ROOMS"13-1",
       "southeast" : F_ROOMS"12-1",
       "southwest" : F_ROOMS"14-1",
       "northeast" : F_ROOMS"12-3",
       "northwest" : F_ROOMS"14-3",
    ] ));
}
