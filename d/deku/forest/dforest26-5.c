#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();
    set_exits(([
       "west" : F_ROOMS"27-5",
       "east" : F_ROOMS"25-5",
       "north" : F_ROOMS"26-6",
       "south" : F_ROOMS"26-4",
       "southeast" : F_ROOMS"25-4",
       "southwest" : F_ROOMS"27-4",
       "northeast" : F_ROOMS"25-6",
       "northwest" : F_ROOMS"27-6",
    ] ));
}
