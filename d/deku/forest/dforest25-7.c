#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"26-7",
       "east" : F_ROOMS"24-7",
       "north" : F_ROOMS"25-8",
       "south" : F_ROOMS"25-6",
       "southeast" : F_ROOMS"24-6",
       "southwest" : F_ROOMS"26-6",
       "northeast" : F_ROOMS"24-8",
       "northwest" : F_ROOMS"26-8",
    ] ));
}
