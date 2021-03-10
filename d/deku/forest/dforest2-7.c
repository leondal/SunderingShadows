#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit SHORETRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"3-7",
       "north" : F_ROOMS"2-8",
       "south" : F_ROOMS"2-6",
       "southwest" : F_ROOMS"3-6",
       "northwest" : F_ROOMS"3-8",
    ] ));
}
