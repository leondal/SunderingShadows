#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"14-3",
       "east" : F_ROOMS"12-3",
       "north" : F_ROOMS"13-4",
       "south" : F_ROOMS"13-2",
       "southeast" : F_ROOMS"12-2",
       "southwest" : F_ROOMS"14-2",
       "northeast" : F_ROOMS"12-4",
       "northwest" : F_ROOMS"14-4",
    ] ));
}
