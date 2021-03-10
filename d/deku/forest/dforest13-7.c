#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"14-7",
       "east" : F_ROOMS"12-7",
       "north" : F_ROOMS"13-8",
       "south" : F_ROOMS"13-6",
       "southeast" : F_ROOMS"12-6",
       "southwest" : F_ROOMS"14-6",
       "northeast" : F_ROOMS"12-8",
       "northwest" : F_ROOMS"14-8",
    ] ));
}
