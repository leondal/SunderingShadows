#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"37-6",
       "east" : F_ROOMS"35-6",
       "north" : F_ROOMS"36-7",
       "south" : F_ROOMS"36-5",
       "southeast" : F_ROOMS"35-5",
       "southwest" : F_ROOMS"37-5",
       "northeast" : F_ROOMS"35-7",
       "northwest" : F_ROOMS"37-7",
    ] ));
}
