#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit WFTRAIL;

void create() {
    ::create();

    set_exits(([
       "east" : F_ROOMS"36-9",
       "north" : F_ROOMS"37-10",
       "south" : F_ROOMS"37-8",
       "southeast" : F_ROOMS"36-8",
       "northeast" : F_ROOMS"36-10",
    ] ));
}
