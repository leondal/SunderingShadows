#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"37-11",
       "east" : F_ROOMS"35-11",
       "south" : F_ROOMS"36-10",
       "southeast" : F_ROOMS"35-10",
       "southwest" : F_ROOMS"37-10",
       "north" : F_ROOMS"36-12",
       "northeast" : F_ROOMS"35-12",
       "northwest" : F_ROOMS"37-12",
    ] ));
}
