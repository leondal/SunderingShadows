#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit ETFTRAIL;

void create() {
    ::create();

    set_exits(([
       "east" : F_ROOMS"14-6",
       "north" : F_ROOMS"15-7",
       "south" : F_ROOMS"15-5",
       "southeast" : F_ROOMS"14-5",
       "northeast" : F_ROOMS"14-7",
    ] ));
}
