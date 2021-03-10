#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit SFTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"37-1",
       "east" : F_ROOMS"35-1",
       "north" : F_ROOMS"36-2",
       "northeast" : F_ROOMS"35-2",
       "northwest" : F_ROOMS"37-2",
    ] ));
}
