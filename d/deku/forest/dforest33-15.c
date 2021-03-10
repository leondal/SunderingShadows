#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"34-15",
       "east" : F_ROOMS"32-15",
       "south" : F_ROOMS"33-14",
       "north" : F_ROOMS"33-16",
       "northwest" : F_ROOMS"34-16",
       "southwest" : F_ROOMS"34-14",
       "southeast" : F_ROOMS"32-14",
       "northeast" : F_ROOMS"32-16"
       
    ] ));
}
