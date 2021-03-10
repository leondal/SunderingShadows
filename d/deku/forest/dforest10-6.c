#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"11-6",
       "east" : F_ROOMS"9-6",
       "north" : F_ROOMS"10-7",
       "south" : F_ROOMS"10-5",
       "southeast" : F_ROOMS"9-5",
       "southwest" : F_ROOMS"11-5",
       "northeast" : F_ROOMS"9-7",
       "northwest" : F_ROOMS"11-7",
    ] ));
}
