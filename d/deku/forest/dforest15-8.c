#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit ETFTRAIL;

void create() {
    ::create();

    set_exits(([
       "east" : F_ROOMS"14-8",
       "north" : F_ROOMS"15-9",
       "south" : F_ROOMS"15-7",
       "southeast" : F_ROOMS"14-7",
       "northeast" : F_ROOMS"14-9",
    ] ));
}
