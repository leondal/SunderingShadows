#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"28-4",
       "east" : F_ROOMS"26-4",
       "north" : F_ROOMS"27-5",
       "south" : F_ROOMS"27-3",
       "southeast" : F_ROOMS"26-3",
       "southwest" : F_ROOMS"28-3",
       "northeast" : F_ROOMS"26-5",
       "northwest" : F_ROOMS"28-5",
    ] ));
}
