#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"35-8",
       "east" : F_ROOMS"33-8",
       "north" : F_ROOMS"34-9",
       "south" : F_ROOMS"34-7",
       "southeast" : F_ROOMS"33-7",
       "southwest" : F_ROOMS"35-7",
       "northeast" : F_ROOMS"33-9",
       "northwest" : F_ROOMS"35-9",
    ] ));
}
