#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"12-9",
       "east" : F_ROOMS"10-9",
       "north" : F_ROOMS"11-10",
       "south" : F_ROOMS"11-8",
       "southeast" : F_ROOMS"10-8",
       "southwest" : F_ROOMS"12-8",
       "northeast" : F_ROOMS"10-10",
       "northwest" : F_ROOMS"12-10",
    ] ));
}
