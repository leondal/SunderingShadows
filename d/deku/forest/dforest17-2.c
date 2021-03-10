#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit STFTRAIL;

void create() {
    ::create();

    set_exits(([
       "east" : F_ROOMS"16-2",
       "south" : F_ROOMS"17-1",
       "southeast" : F_ROOMS"16-1",
       "west" : F_ROOMS"18-2",
       "southwest" : F_ROOMS"18-1",
    ] ));
}
