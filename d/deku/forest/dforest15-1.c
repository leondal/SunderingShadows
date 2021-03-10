#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit SFTRAIL;

void create() {
    ::create();

    set_exits(([
       "east" : F_ROOMS"14-1",
       "north" : F_ROOMS"15-2",
       "northeast" : F_ROOMS"14-2",
       "west" : F_ROOMS"16-1",
       "northwest" : F_ROOMS"16-2",
    ] ));
}
