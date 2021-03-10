#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit LAKEBANK;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"32-3",
       "east" : F_ROOMS"30-3",
       "south" : F_ROOMS"31-2",
       "southeast" : F_ROOMS"30-2",
       "southwest" : F_ROOMS"32-2",
    ] ));
}
