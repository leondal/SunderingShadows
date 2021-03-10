#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit WFTRAIL;

void create() {
    ::create();

    set_exits(([
       "east" : F_ROOMS"36-6",
       "north" : F_ROOMS"37-7",
       "south" : F_ROOMS"37-5",
       "southeast" : F_ROOMS"36-5",
       "northeast" : F_ROOMS"36-7",
    ] ));
}
