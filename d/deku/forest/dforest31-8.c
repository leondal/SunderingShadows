#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit LAKEBANK;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"32-8",
       "east" : F_ROOMS"30-8",
       "north" : F_ROOMS"31-9",
       "northeast" : F_ROOMS"30-9",
       "northwest" : F_ROOMS"32-9",
    ] ));
}
