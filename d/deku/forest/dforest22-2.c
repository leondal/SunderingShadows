#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit STFTRAIL;

void create() {
    ::create();

    set_exits(([
       "east" : F_ROOMS"21-2",
       "south" : F_ROOMS"22-1",
       "southeast" : F_ROOMS"21-1",
       "west" : F_ROOMS"23-2",
       "northwest" : F_ROOMS"23-3",
       "southwest" : F_ROOMS"23-1",
    ] ));
}
