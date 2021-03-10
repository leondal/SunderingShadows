#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit ETFTRAIL;

void create() {
    ::create();

    set_exits(([
       "east" : F_ROOMS"14-9",
       "north" : F_ROOMS"15-10",
       "south" : F_ROOMS"15-8",
       "southeast" : F_ROOMS"14-8",
       "northeast" : F_ROOMS"14-10",
       "northwest" : F_ROOMS"16-10",
    ] ));
}
