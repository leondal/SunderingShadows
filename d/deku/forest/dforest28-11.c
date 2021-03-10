#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit NFTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"29-11",
       "east" : F_ROOMS"27-11",
       "south" : F_ROOMS"28-10",
       "southeast" : F_ROOMS"27-10",
       "southwest" : F_ROOMS"29-10",
    ] ));
}
