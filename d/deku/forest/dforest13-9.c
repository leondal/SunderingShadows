#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"14-9",
       "east" : F_ROOMS"12-9",
       "north" : F_ROOMS"13-10",
       "south" : F_ROOMS"13-8",
       "southeast" : F_ROOMS"12-8",
       "southwest" : F_ROOMS"14-8",
       "northeast" : F_ROOMS"12-10",
       "northwest" : F_ROOMS"14-10",
    ] ));
}
