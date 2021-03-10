#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit NTFTRAIL;

void create() {
    ::create();

    set_exits(([
       "east" : F_ROOMS"15-10",
       "north" : F_ROOMS"16-11",
       "southeast" : F_ROOMS"15-9",
       "northeast" : F_ROOMS"15-11",
       "west" : F_ROOMS"17-10",
       "northwest" : F_ROOMS"17-11",
    ] ));
}
