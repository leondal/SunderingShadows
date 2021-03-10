#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit ETFTRAIL;

void create() {
    ::create();

    set_exits(([
       "east" : F_ROOMS"14-4",
       "north" : F_ROOMS"15-5",
       "south" : F_ROOMS"15-3",
       "southeast" : F_ROOMS"14-3",
       "northeast" : F_ROOMS"14-5",
    ] ));
}
