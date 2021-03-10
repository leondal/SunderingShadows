#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit SFTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"7-1",
       "east" : F_ROOMS"5-1",
       "north" : F_ROOMS"6-2",
       "northeast" : F_ROOMS"5-2",
       "northwest" : F_ROOMS"7-2",
    ] ));
}
