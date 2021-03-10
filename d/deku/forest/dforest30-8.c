#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit LAKEBANK;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"31-8",
       "east" : F_ROOMS"29-8",
       "north" : F_ROOMS"30-9",
       "south" : F_ROOMS"30-7",
       "southeast" : F_ROOMS"29-7",
       "northeast" : F_ROOMS"29-9",
       "northwest" : F_ROOMS"31-9",
    ] ));
}
