#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit NFTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"25-11",
       "east" : F_ROOMS"23-11",
       "south" : F_ROOMS"24-10",
       "southeast" : F_ROOMS"23-10",
       "southwest" : F_ROOMS"25-10",
    ] ));
}
