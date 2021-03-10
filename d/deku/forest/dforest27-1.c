#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"28-1",
       "east" : F_ROOMS"26-1",
       "north" : F_ROOMS"27-2",
       "northeast" : F_ROOMS"26-2",
       "northwest" : F_ROOMS"28-2",
    ] ));
}
