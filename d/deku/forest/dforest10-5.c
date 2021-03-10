#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"11-5",
       "east" : F_ROOMS"9-5",
       "north" : F_ROOMS"10-6",
       "south" : F_ROOMS"10-4",
       "southeast" : F_ROOMS"9-4",
       "southwest" : F_ROOMS"11-4",
       "northeast" : F_ROOMS"9-6",
       "northwest" : F_ROOMS"11-6",
    ] ));
}
