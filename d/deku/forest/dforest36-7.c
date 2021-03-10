#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"37-7",
       "east" : F_ROOMS"35-7",
       "north" : F_ROOMS"36-8",
       "south" : F_ROOMS"36-6",
       "southeast" : F_ROOMS"35-6",
       "southwest" : F_ROOMS"37-6",
       "northeast" : F_ROOMS"35-8",
       "northwest" : F_ROOMS"37-8",
    ] ));
}
