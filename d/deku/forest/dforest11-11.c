#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit NFTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"12-11",
       "east" : F_ROOMS"10-11",
       "south" : F_ROOMS"11-10",
       "southeast" : F_ROOMS"10-10",
       "southwest" : F_ROOMS"12-10",
    ] ));
}
