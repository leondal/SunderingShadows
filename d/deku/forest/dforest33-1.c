#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit SFTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"34-1",
       "east" : F_ROOMS"32-1",
       "north" : F_ROOMS"33-2",
       "northeast" : F_ROOMS"32-2",
       "northwest" : F_ROOMS"34-2",
    ] ));
}
