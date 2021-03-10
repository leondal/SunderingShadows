#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"37-8",
       "east" : F_ROOMS"35-8",
       "north" : F_ROOMS"36-9",
       "south" : F_ROOMS"36-7",
       "southeast" : F_ROOMS"35-7",
       "southwest" : F_ROOMS"37-7",
       "northeast" : F_ROOMS"35-9",
       "northwest" : F_ROOMS"37-9",
    ] ));
}
