#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"36-3",
       "east" : F_ROOMS"34-3",
       "north" : F_ROOMS"35-4",
       "south" : F_ROOMS"35-2",
       "southeast" : F_ROOMS"34-2",
       "southwest" : F_ROOMS"36-2",
       "northeast" : F_ROOMS"34-4",
       "northwest" : F_ROOMS"36-4",
    ] ));
}
