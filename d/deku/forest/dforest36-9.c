#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"37-9",
       "east" : F_ROOMS"35-9",
       "north" : F_ROOMS"36-10",
       "south" : F_ROOMS"36-8",
       "southeast" : F_ROOMS"35-8",
       "southwest" : F_ROOMS"37-8",
       "northeast" : F_ROOMS"35-10",
       "northwest" : F_ROOMS"37-10",
    ] ));
}
