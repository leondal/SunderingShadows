#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit LAKEBANK;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"33-6",
       "north" : F_ROOMS"32-7",
       "south" : F_ROOMS"32-5",
       "southwest" : F_ROOMS"33-5",
       "northwest" : F_ROOMS"33-7",
    ] ));
}
