#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"25-8",
       "east" : F_ROOMS"23-8",
       "north" : F_ROOMS"24-9",
       "south" : F_ROOMS"24-7",
       "southeast" : F_ROOMS"23-7",
       "southwest" : F_ROOMS"25-7",
       "northeast" : F_ROOMS"23-9",
       "northwest" : F_ROOMS"25-9",
    ] ));
}
