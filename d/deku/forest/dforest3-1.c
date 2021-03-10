#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit SFTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"4-1",
       "east" : F_ROOMS"2-1",
       "north" : F_ROOMS"3-2",
       "northeast" : F_ROOMS"3-2",
       "northwest" : F_ROOMS"4-2",
    ] ));
}
