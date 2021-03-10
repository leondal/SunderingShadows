#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit ETFTRAIL;

void create() {
    ::create();

    set_exits(([
       "east" : F_ROOMS"14-7",
       "north" : F_ROOMS"15-8",
       "south" : F_ROOMS"15-6",
       "southeast" : F_ROOMS"14-6",
       "northeast" : F_ROOMS"14-8",
    ] ));
}
