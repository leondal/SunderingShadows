#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit WFTRAIL;

void create() {
    ::create();

    set_exits(([
       "east" : F_ROOMS"36-7",
       "north" : F_ROOMS"37-8",
       "south" : F_ROOMS"37-6",
       "southeast" : F_ROOMS"36-6",
       "northeast" : F_ROOMS"36-8",
    ] ));
}
