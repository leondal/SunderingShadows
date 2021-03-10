#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit WFTRAIL;

void create() {
    ::create();

    set_exits(([
       "east" : F_ROOMS"36-10",
       "north" : F_ROOMS"37-11",
       "south" : F_ROOMS"37-9",
       "southeast" : F_ROOMS"36-9",
       "northeast" : F_ROOMS"36-11",
    ] ));
}
