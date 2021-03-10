#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"35-7",
       "east" : F_ROOMS"33-7",
       "north" : F_ROOMS"34-8",
       "south" : F_ROOMS"34-6",
       "southeast" : F_ROOMS"33-6",
       "southwest" : F_ROOMS"35-6",
       "northeast" : F_ROOMS"33-8",
       "northwest" : F_ROOMS"35-8",
    ] ));
}
