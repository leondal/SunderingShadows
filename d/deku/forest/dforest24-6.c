#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"25-6",
       "east" : F_ROOMS"23-6",
       "north" : F_ROOMS"24-7",
       "south" : F_ROOMS"24-5",
       "southeast" : F_ROOMS"23-5",
       "southwest" : F_ROOMS"25-5",
       "northeast" : F_ROOMS"23-7",
       "northwest" : F_ROOMS"25-7",
    ] ));
}
