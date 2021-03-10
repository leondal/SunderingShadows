#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"14-8",
       "east" : F_ROOMS"12-8",
       "north" : F_ROOMS"13-9",
       "south" : F_ROOMS"13-7",
       "southeast" : F_ROOMS"12-7",
       "southwest" : F_ROOMS"14-7",
       "northeast" : F_ROOMS"12-9",
       "northwest" : F_ROOMS"14-9",
    ] ));
}
