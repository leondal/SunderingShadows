#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit WFTRAIL;

void create() {
    ::create();
    set_exits(([
       "east" : F_ROOMS"36-5",
       "north" : F_ROOMS"37-6",
       "south" : F_ROOMS"37-4",
       "southeast" : F_ROOMS"36-4",
       "northeast" : F_ROOMS"36-6",
    ] ));
}
