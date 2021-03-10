#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit SHORETRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"3-3",
       "north" : F_ROOMS"2-4",
       "south" : F_ROOMS"2-2",
       "southwest" : F_ROOMS"3-2",
       "northwest" : F_ROOMS"3-4",
    ] ));
}
