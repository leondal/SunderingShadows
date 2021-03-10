#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"15-4",
       "east" : F_ROOMS"13-4",
       "north" : F_ROOMS"14-5",
       "south" : F_ROOMS"14-3",
       "southeast" : F_ROOMS"13-3",
       "southwest" : F_ROOMS"15-3",
       "northeast" : F_ROOMS"13-5",
       "northwest" : F_ROOMS"15-5",
    ] ));
}
