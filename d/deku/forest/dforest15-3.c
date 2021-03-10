#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit ETFTRAIL;

void create() {
    ::create();

    set_exits(([
       "east" : F_ROOMS"14-3",
       "north" : F_ROOMS"15-4",
       "south" : F_ROOMS"15-2",
       "southeast" : F_ROOMS"14-2",
       "northeast" : F_ROOMS"14-4",
       "southwest" : F_ROOMS"16-2",
    ] ));
}
