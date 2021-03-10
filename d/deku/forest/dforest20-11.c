#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "east" : F_ROOMS"19-11",
       "south" : F_ROOMS"20-10",
       "southeast" : F_ROOMS"19-10",
       "west" : F_ROOMS"21-11",
       "southwest" : F_ROOMS"21-10",
    ] ));
}
