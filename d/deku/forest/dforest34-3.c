#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"35-3",
       "east" : F_ROOMS"33-3",
       "north" : F_ROOMS"34-4",
       "south" : F_ROOMS"34-2",
       "southeast" : F_ROOMS"33-2",
       "southwest" : F_ROOMS"35-2",
       "northeast" : F_ROOMS"33-4",
       "northwest" : F_ROOMS"35-4",
    ] ));
}
