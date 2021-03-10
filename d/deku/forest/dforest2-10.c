#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit SHORETRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"3-10",
       "north" : F_ROOMS"2-11",
       "south" : F_ROOMS"2-9",
       "southwest" : F_ROOMS"3-9",
       "northwest" : F_ROOMS"3-11",
    ] ));
}
