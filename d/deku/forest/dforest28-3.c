#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"29-3",
       "east" : F_ROOMS"27-3",
       "north" : F_ROOMS"28-4",
       "south" : F_ROOMS"28-2",
       "southeast" : F_ROOMS"27-2",
       "southwest" : F_ROOMS"29-2",
       "northeast" : F_ROOMS"27-4",
       "northwest" : F_ROOMS"29-4",
    ] ));
}
