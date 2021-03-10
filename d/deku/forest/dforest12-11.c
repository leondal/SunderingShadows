#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit NFTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"13-11",
       "east" : F_ROOMS"11-11",
       "south" : F_ROOMS"12-10",
       "southeast" : F_ROOMS"11-10",
       "southwest" : F_ROOMS"13-10",
    ] ));
}
