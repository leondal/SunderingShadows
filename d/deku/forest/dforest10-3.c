#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"11-3",
       "east" : F_ROOMS"9-3",
       "north" : F_ROOMS"10-4",
       "south" : F_ROOMS"10-2",
       "southeast" : F_ROOMS"9-2",
       "southwest" : F_ROOMS"11-2",
       "northeast" : F_ROOMS"9-4",
       "northwest" : F_ROOMS"11-4",
    ] ));
}
