#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"11-7",
       "east" : F_ROOMS"9-7",
       "north" : F_ROOMS"10-8",
       "south" : F_ROOMS"10-6",
       "southeast" : F_ROOMS"9-6",
       "southwest" : F_ROOMS"11-6",
       "northeast" : F_ROOMS"9-8",
       "northwest" : F_ROOMS"11-8",
    ] ));
}
