#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit WFTRAIL;

void create() {
    ::create();

    set_exits(([
       "east" : F_ROOMS"36-4",
       "north" : F_ROOMS"37-5",
       "south" : F_ROOMS"37-3",
       "southeast" : F_ROOMS"36-3",
       "northeast" : F_ROOMS"36-5",
    ] ));
}
