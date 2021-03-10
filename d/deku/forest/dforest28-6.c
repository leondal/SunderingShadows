#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"29-6",
       "east" : F_ROOMS"27-6",
       "north" : F_ROOMS"28-7",
       "south" : F_ROOMS"28-5",
       "southeast" : F_ROOMS"27-5",
       "southwest" : F_ROOMS"29-5",
       "northeast" : F_ROOMS"27-7",
       "northwest" : F_ROOMS"29-7",
    ] ));
}
