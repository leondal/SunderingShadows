#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit LAKEBANK;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"33-7",
       "north" : F_ROOMS"32-8",
       "south" : F_ROOMS"32-6",
       "southwest" : F_ROOMS"33-6",
       "northwest" : F_ROOMS"33-8",
    ] ));
}
