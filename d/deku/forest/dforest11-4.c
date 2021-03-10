#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"12-4",
       "east" : F_ROOMS"10-4",
       "north" : F_ROOMS"11-5",
       "south" : F_ROOMS"11-3",
       "southeast" : F_ROOMS"10-3",
       "southwest" : F_ROOMS"12-3",
       "northeast" : F_ROOMS"10-5",
       "northwest" : F_ROOMS"12-5",
    ] ));
}
