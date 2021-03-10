#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit NFTRAIL;

void create() {
    ::create();

    set_exits(([
       "east" : F_ROOMS"15-11",
       "south" : F_ROOMS"16-10",
       "southeast" : F_ROOMS"15-10",
       "west" : F_ROOMS"17-11",
       "southwest" : F_ROOMS"17-10",
    ] ));
}
