#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"37-4",
       "east" : F_ROOMS"35-4",
       "north" : F_ROOMS"36-5",
       "south" : F_ROOMS"36-3",
       "southeast" : F_ROOMS"35-3",
       "southwest" : F_ROOMS"37-3",
       "northeast" : F_ROOMS"35-5",
       "northwest" : F_ROOMS"37-5",
    ] ));
}
