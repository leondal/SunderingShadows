#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit WFTRAIL;

void create() {
    ::create();

    set_exits(([
       "east" : F_ROOMS"36-12",
       "south" : F_ROOMS"37-11",
       "north" : F_ROOMS"37-13",
       "southeast" : F_ROOMS"36-11",
       "northeast" : F_ROOMS"36-13",
       
    ] ));
}
