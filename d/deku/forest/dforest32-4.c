#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit LAKEBANK;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"33-4",
       "north" : F_ROOMS"32-5",
       "south" : F_ROOMS"32-3",
       "southwest" : F_ROOMS"33-3",
       "northwest" : F_ROOMS"33-5",
    ] ));
}
