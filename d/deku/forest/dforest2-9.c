#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit SHORETRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"3-9",
       "north" : F_ROOMS"2-10",
       "south" : F_ROOMS"2-8",
       "southwest" : F_ROOMS"3-8",
       "northwest" : F_ROOMS"3-10",
    ] ));
}
