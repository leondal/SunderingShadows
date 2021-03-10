#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"13-10",
       "east" : F_ROOMS"11-10",
       "north" : F_ROOMS"12-11",
       "south" : F_ROOMS"12-9",
       "southeast" : F_ROOMS"11-9",
       "southwest" : F_ROOMS"13-9",
       "northeast" : F_ROOMS"11-11",
       "northwest" : F_ROOMS"13-11",
    ] ));
}
