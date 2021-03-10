#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit LAKEBANK;

void create() {
    ::create();

    set_exits(([
       "east" : F_ROOMS"29-4",
       "north" : F_ROOMS"30-5",
       "south" : F_ROOMS"30-3",
       "southeast" : F_ROOMS"29-3",
       "northeast" : F_ROOMS"29-5",
    ] ));
}
