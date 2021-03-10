#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"13-7",
       "east" : F_ROOMS"11-7",
       "north" : F_ROOMS"12-8",
       "south" : F_ROOMS"12-6",
       "southeast" : F_ROOMS"11-6",
       "southwest" : F_ROOMS"13-6",
       "northeast" : F_ROOMS"11-8",
       "northwest" : F_ROOMS"13-8",
    ] ));
}
