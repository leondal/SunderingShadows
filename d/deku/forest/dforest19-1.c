#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit SFTRAIL;

void create() {
    ::create();

    set_exits(([
       "east" : F_ROOMS"18-1",
       "north" : F_ROOMS"19-2",
       "northeast" : F_ROOMS"18-2",
       "west" : F_ROOMS"20-1",
       "northwest" : F_ROOMS"20-2",
    ] ));
}
