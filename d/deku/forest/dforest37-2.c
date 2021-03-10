#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit WFTRAIL;

void create() {
    ::create();

    set_exits(([
       "east" : F_ROOMS"36-2",
       "north" : F_ROOMS"37-3",
       "south" : F_ROOMS"37-1",
       "southeast" : F_ROOMS"36-1",
       "northeast" : F_ROOMS"36-3",
    ] ));
}
