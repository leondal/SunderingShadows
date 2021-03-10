#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit SHORETRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"3-2",
       "north" : F_ROOMS"2-3",
       "south" : F_ROOMS"2-1",
       "southwest" : F_ROOMS"3-1",
       "northwest" : F_ROOMS"3-3",
    ] ));
}
