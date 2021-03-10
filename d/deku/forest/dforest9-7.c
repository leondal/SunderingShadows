#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"10-7",
       "east" : F_ROOMS"8-7",
       "north" : F_ROOMS"9-8",
       "south" : F_ROOMS"9-6",
       "southeast" : F_ROOMS"8-6",
       "southwest" : F_ROOMS"10-6",
       "northeast" : F_ROOMS"8-8",
       "northwest" : F_ROOMS"10-8",
    ] ));
}
