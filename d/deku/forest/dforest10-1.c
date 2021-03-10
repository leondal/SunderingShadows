#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit SFTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"11-1",
       "east" : F_ROOMS"9-1",
       "north" : F_ROOMS"10-2",
       "northeast" : F_ROOMS"9-2",
       "northwest" : F_ROOMS"11-2",
    ] ));
}
