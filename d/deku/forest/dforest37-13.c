#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit WFTRAIL;

void create() {
    ::create();

    set_exits(([
       "east" : F_ROOMS"36-13",
       "south" : F_ROOMS"37-12",
       "north" : F_ROOMS"37-14",
       "southeast" : F_ROOMS"36-12",
//       "northeast" : F_ROOMS"36-14",

       
    ] ));
}
