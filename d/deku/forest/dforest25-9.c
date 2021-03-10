#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"26-9",
       "east" : F_ROOMS"24-9",
       "north" : F_ROOMS"25-10",
       "south" : F_ROOMS"25-8",
       "southeast" : F_ROOMS"24-8",
       "southwest" : F_ROOMS"26-8",
       "northeast" : F_ROOMS"24-10",
       "northwest" : F_ROOMS"26-10",
    ] ));
}
