#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();
    set_exits(([
       "west" : F_ROOMS"25-5",
       "east" : F_ROOMS"23-5",
       "north" : F_ROOMS"24-6",
       "south" : F_ROOMS"24-4",
       "southeast" : F_ROOMS"23-4",
       "southwest" : F_ROOMS"25-4",
       "northeast" : F_ROOMS"23-6",
       "northwest" : F_ROOMS"25-6",
    ] ));
}
