#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit SFTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"15-1",
       "east" : F_ROOMS"13-1",
       "north" : F_ROOMS"14-2",
       "northeast" : F_ROOMS"13-2",
       "northwest" : F_ROOMS"15-2",
    ] ));
}
