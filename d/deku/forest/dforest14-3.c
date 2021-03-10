#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"15-3",
       "east" : F_ROOMS"13-3",
       "north" : F_ROOMS"14-4",
       "south" : F_ROOMS"14-2",
       "southeast" : F_ROOMS"13-2",
       "southwest" : F_ROOMS"15-2",
       "northeast" : F_ROOMS"13-4",
       "northwest" : F_ROOMS"15-4",
    ] ));
}
