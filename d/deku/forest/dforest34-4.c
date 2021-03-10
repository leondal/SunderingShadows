#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"35-4",
       "east" : F_ROOMS"33-4",
       "north" : F_ROOMS"34-5",
       "south" : F_ROOMS"34-3",
       "southeast" : F_ROOMS"33-3",
       "southwest" : F_ROOMS"35-3",
       "northeast" : F_ROOMS"33-5",
       "northwest" : F_ROOMS"35-5",
    ] ));
}
