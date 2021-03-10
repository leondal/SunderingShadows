#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"13-8",
       "east" : F_ROOMS"11-8",
       "north" : F_ROOMS"12-9",
       "south" : F_ROOMS"12-7",
       "southeast" : F_ROOMS"11-7",
       "southwest" : F_ROOMS"13-7",
       "northeast" : F_ROOMS"11-9",
       "northwest" : F_ROOMS"13-9",
    ] ));
}
