#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit NFTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"6-11",
       "east" : F_ROOMS"4-11",
       "south" : F_ROOMS"5-10",
       "southeast" : F_ROOMS"4-10",
       "southwest" : F_ROOMS"6-10",
    ] ));
}
