#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit NFTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"5-11",
       "east" : F_ROOMS"3-11",
       "south" : F_ROOMS"4-10",
       "southeast" : F_ROOMS"3-10",
       "southwest" : F_ROOMS"5-10",
    ] ));
}
