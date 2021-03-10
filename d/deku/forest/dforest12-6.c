#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"13-6",
       "east" : F_ROOMS"11-6",
       "north" : F_ROOMS"12-7",
       "south" : F_ROOMS"12-5",
       "southeast" : F_ROOMS"11-5",
       "southwest" : F_ROOMS"13-5",
       "northeast" : F_ROOMS"11-7",
       "northwest" : F_ROOMS"13-7",
    ] ));
}
