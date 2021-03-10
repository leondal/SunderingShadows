#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit WFTRAIL;

void create() {
    ::create();

    set_exits(([
       "east" : F_ROOMS"36-3",
       "north" : F_ROOMS"37-4",
       "south" : F_ROOMS"37-2",
       "southeast" : F_ROOMS"36-2",
       "northeast" : F_ROOMS"36-4",
    ] ));
}
