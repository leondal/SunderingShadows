#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit SFTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"24-1",
       "north" : F_ROOMS"23-2",
       "northwest" : F_ROOMS"24-2",
       "east" : F_ROOMS"22-1",
       "northeast" : F_ROOMS"22-2",
    ] ));
}
