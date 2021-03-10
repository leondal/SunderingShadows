#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit LAKEBANK;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"33-3",
       "east" : F_ROOMS"31-3",
       "north" : F_ROOMS"32-4",
       "south" : F_ROOMS"32-2",
       "southeast" : F_ROOMS"31-2",
       "southwest" : F_ROOMS"33-2",
       "northwest" : F_ROOMS"33-4",
    ] ));
}
