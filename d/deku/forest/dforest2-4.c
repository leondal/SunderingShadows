#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit SHORETRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"3-4",
       "north" : F_ROOMS"2-5",
       "south" : F_ROOMS"2-3",
       "southwest" : F_ROOMS"3-3",
       "northwest" : F_ROOMS"3-5",
    ] ));
}
