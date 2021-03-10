#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"35-6",
       "east" : F_ROOMS"33-6",
       "north" : F_ROOMS"34-7",
       "south" : F_ROOMS"34-5",
       "southeast" : F_ROOMS"33-5",
       "southwest" : F_ROOMS"35-5",
       "northeast" : F_ROOMS"33-7",
       "northwest" : F_ROOMS"35-7",
    ] ));
}
