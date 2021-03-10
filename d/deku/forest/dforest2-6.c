#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit SHORETRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"3-6",
       "north" : F_ROOMS"2-7",
       "south" : F_ROOMS"2-5",
       "southwest" : F_ROOMS"3-5",
       "northwest" : F_ROOMS"3-7",
    ] ));
}
