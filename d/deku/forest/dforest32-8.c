#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit LAKEBANK;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"33-8",
       "east" : F_ROOMS"31-8",
       "north" : F_ROOMS"32-9",
       "south" : F_ROOMS"32-7",
       "southwest" : F_ROOMS"33-7",
       "northeast" : F_ROOMS"31-9",
       "northwest" : F_ROOMS"33-9",
    ] ));
}
