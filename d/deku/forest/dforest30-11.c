#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit NFTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"31-11",
       "east" : F_ROOMS"29-11",
       "south" : F_ROOMS"30-10",
       "southeast" : F_ROOMS"29-10",
       "southwest" : F_ROOMS"31-10",
    ] ));
}
